#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/collision/EnemyCollision.h"
#include "../../../header/math/Random.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/data/ENEMY_ANIMATION.h"

const float Enemy::PLAYER_DISTANCE = 10;
Enemy::Enemy(const Transform & _transform)
	:Actor(_transform, MODEL_ID::ENEMY,
		Sphere(GSvector3(0, 0, 0), 1.0f),
		Actor_Tag::ENEMY),
	m_group(std::make_shared<CollisionGroup>(this)),
	m_state(ESTATE::SPAWN),
	m_stay_timer(5),
	m_velocity(0, 0, 0),
	m_hp(100)
{
}
void Enemy::addCollisionGroup(CollisionManager * _manager)
{
	_manager->add(m_group);
}
void Enemy::initialize()
{
	Collision_Ptr actor = std::make_shared<EnemyCollision>(this);
	m_group->add(actor);
	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::SPAWN));
	m_state = ESTATE::SPAWN;
	m_stay_timer.initialize();
	m_hp = 100;
}
void Enemy::update(float deltatime)
{
	m_transform.translate(m_velocity);
	m_transform.m_rotate = m_rotate;
	m_animatorOne.update(deltatime);
	state(deltatime);
	sphereChases(GSvector3(0, 1, 0));
	if (m_hp <= 0)
	{
		m_isDead = true;
		m_group->initialize();
	}
}

void Enemy::draw(const Renderer & _renderer, const Camera & _camera)
{
	//‹——£‚Ì“§‰ß‚È‚Ç‚Íshader‚É”C‚¹‚é—\’è
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	//_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::PLAYER, m_transform, m_animatorOne, m_Color);
	m_animatorOne.draw(m_transform);
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
	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DAMAGE));
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
	//Math::Random rand;
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

		break;
	case ESTATE::DAMAGE:
		if (m_animatorOne.isEndCurrentAnimation())
		{
			m_state = ESTATE::STAND;
		}
		break;
	}
}

const bool Enemy::isDamageState() const
{
	return m_state == ESTATE::MOVE || m_state == ESTATE::ATTACK;
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


void Enemy::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.m_translate;
	_player->look_at(_camera, &target);
}

void Enemy::think(Player * _player)
{
	if (m_state == ESTATE::DAMAGE || m_state == ESTATE::ATTACK || m_state == ESTATE::SPAWN)return;
	if (!m_stay_timer.isEnd())return;

	float distance = distanceActor(*_player);
	Math::Random rnd;
	if (rnd(0, 200) == 0)
	{
		m_state = ESTATE::STAND;
		m_stay_timer.initialize();
		return;
	}
	if (isNear(distance))
	{
		m_state = ESTATE::SLIDE;
		slide(_player);
		return;
	}
	move(_player);
	m_state = ESTATE::MOVE;
}
