#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/collision/EnemyCollision.h"
#include "../../../header/math/Random.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/data/ENEMY_ANIMATION.h"
#include "../../../header/collision/EnemyAttackCollision.h"
const float Enemy::PLAYER_DISTANCE = 10;
Enemy::Enemy(const Transform & _transform)
	:Actor(_transform, MODEL_ID::ENEMY,
		Sphere(GSvector3(0, 0, 0), 1.0f),
		Actor_Tag::ENEMY),
	m_state(ESTATE::SPAWN),
	m_stay_timer(2),
	m_velocity(0, 0, 0),
	m_hp(100),
	m_incidence()
{
}
Enemy::~Enemy()
{
}
void Enemy::initialize()
{
	Actor::initialize();
	Collision_Ptr actor = std::make_shared<EnemyCollision>(this);
	m_collision.add(actor);
	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::SPAWN),true,false);
	m_state = ESTATE::SPAWN;
	m_stay_timer.initialize();
	m_hp = 100;
}
void Enemy::update(float deltatime)
{
	m_transform.translate(m_velocity);
	m_transform.m_rotate = m_rotate;
	Math::Clamp clamp;
	m_transform.m_translate = clamp(m_transform.m_translate,GSvector3(-20.0f,-10,-20.0f),GSvector3(20.0f,10,20.0f));

	m_animatorOne.update(deltatime);
	state(deltatime);
	sphereChases(GSvector3(0, 1, 0));
	if (m_hp <= 0)
	{
		m_state = ESTATE::DEAD;
	}
	m_collision.update(deltatime);
}

void Enemy::draw(const Renderer & _renderer, const Camera & _camera)
{
	//‹——£‚Ì“§‰ß‚È‚Ç‚Íshader‚É”C‚¹‚é—\’è
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	m_collision.draw(_renderer);
	m_animatorOne.draw(_renderer, m_transform);
	_renderer.getDraw2D().string(std::to_string(m_hp), &GSvector2(500, 80), 30);
}

void Enemy::collisionChase(EnemyCollision * _collision)
{
	_collision->chase(m_transform.m_translate);
}

void Enemy::damage(Player * _player)
{
	if (isDamageState())return;
	m_state = ESTATE::DAMAGE;
	//‚±‚±
	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DAMAGE),true,false,false,10.0f,1.5f);
	m_transform.translate_front(-0.1f);
	m_hp -= 10;
	_player->gaugeAdd();
}

const bool Enemy::isNear(float _distance) const
{
	return _distance < PLAYER_DISTANCE;
}

void Enemy::state(float deltaTime)
{
	switch (m_state)
	{
	case ESTATE::SPAWN:
		if (m_animatorOne.isEndCurrentAnimation())
		{
			m_state = ESTATE::STAND;
		}
		break;
	case ESTATE::STAND:
		m_velocity = GSvector3(0, 0, 0);
		m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::STAND), true, true);
		m_stay_timer.update(deltaTime);
		break;
	case ESTATE::MOVE:
		m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::RUN), true, true);
		break;
	case ESTATE::SLIDE:
		m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::SLIDE), true, true);
		break;
	case ESTATE::ATTACK:
		m_incidence.setWorldTransform(m_animatorOne.getOrientedMat(8));
		m_incidence.synthesisWorldTransform(m_transform);
		m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::ATTACK), false, false, false, 0);
		if (m_animatorOne.isEndCurrentAnimation())
		{
			m_state = ESTATE::STAND;
		}
		break;
	case ESTATE::DAMAGE:
		if (m_animatorOne.isEndCurrentAnimation())
		{
			m_state = ESTATE::STAND;
		}
		break;
	case ESTATE::DEAD:
		m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DEAD));
		m_Color.a -= 1/m_animatorOne.getCurrentAnimationEndTime();
		m_isDead=m_animatorOne.isEndCurrentAnimation();
		break;
	}
}

const bool Enemy::isDamageState() const
{
	return m_state == ESTATE::MOVE || m_state == ESTATE::ATTACK||m_state==ESTATE::DEAD;
}

void Enemy::slide(Actor * _actor)
{
	m_velocity = m_transform.left()*0.03f;
	if (_actor == nullptr) return;
	m_rotate = targetDirection(*_actor);
}

void Enemy::move(Actor * _actor)
{
	m_velocity = m_transform.front()*0.05f;
	if (_actor == nullptr) return;
	m_rotate = (targetDirection(*_actor));
}

void Enemy::attack_start()
{
	m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::ATTACK), false,false,false,0);
	float end = m_animatorOne.getCurrentAnimationEndTime()/60.0f;
	Collision_Ptr actor = std::make_shared<EnemyAttackCollision>(&m_incidence, end);
	m_collision.add(actor);
	m_state = ESTATE::ATTACK;
}

void Enemy::stay_start()
{
	Math::Random rnd;
	m_state = ESTATE::STAND;
	m_stay_timer.setEndTime(rnd(1.0f, 4.0f));
	m_stay_timer.initialize();
}

void Enemy::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.m_translate;
	_player->look_at(_camera, &target);
}

void Enemy::think(Player * _player)
{
	if (m_state == ESTATE::DAMAGE || m_state == ESTATE::ATTACK || m_state == ESTATE::SPAWN)return;
	if (!m_stay_timer.isEnd())return;
	Math::Random rnd;
	if (rnd(0, 200) == 0)
	{
		stay_start();
		return;
	}
	if (rnd(0, 200) == 0)
	{
		attack_start();
		return;
	}
	float distance = distanceActor(*_player);
	if (isNear(distance))
	{
		m_state = ESTATE::SLIDE;
		slide(_player);
		return;
	}
	move(_player);
	m_state = ESTATE::MOVE;
}
