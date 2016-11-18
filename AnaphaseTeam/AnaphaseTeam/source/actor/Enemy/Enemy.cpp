#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/collision/EnemyCollision.h"
#include "../../../header/math/Random.h"
#include "../../../header/actor/Player/Player.h"
#include "../../../header/data/ENEMY_ANIMATION.h"

const float Enemy::PLAYER_DISTANCE=10;
Enemy::Enemy(const Transform & _transform)
	:Actor(_transform, MODEL_ID::ENEMY,
		Sphere(GSvector3(0, 0, 0), 1.0f),
		Actor_Tag::ENEMY),
	m_group(std::make_shared<CollisionGroup>(this)),
	m_state(ESTATE::SPAWN)
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
}
void Enemy::update(float deltatime)
{
	m_animatorOne.update(deltatime);
	state();
	sphereChases(GSvector3(0, 1, 0));
}

void Enemy::draw(const Renderer & _renderer, const Camera & _camera)
{
	//‹——£‚Ì“§‰ß‚È‚Ç‚Íshader‚É”C‚¹‚é—\’è
	FALSE_RETURN(isInsideView(_camera));
	alphaBlend(_camera);
	//_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::PLAYER, m_transform, m_animatorOne, m_Color);
	m_animatorOne.draw(m_transform);
}

void Enemy::collisionChase(EnemyCollision * _collision)
{
	_collision->chase(m_transform.m_translate);
}

void Enemy::damage(Player * _player)
{
	if (isDamageState())return;
	m_state = ESTATE::DAMAGE;
	m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::DAMAGE));
	m_transform.translate_front(-0.1f);
}

const bool Enemy::isNear(float _distance) const
{
	return _distance <PLAYER_DISTANCE;
}

void Enemy::state()
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
		m_animatorOne.changeAnimation(static_cast<GSuint>(ENEMY_ANIMATION::STAND),true,true);
		break;
	case ESTATE::MOVE:
		break;
	case ESTATE::SLIDE:
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
	return m_state == ESTATE::STAND || m_state == ESTATE::MOVE || m_state == ESTATE::ATTACK;
}

void Enemy::slide(Actor * _actor)
{
	m_transform.m_rotate = (targetDirection(*_actor));
	m_transform.translate_left(0.07f);
}

void Enemy::move(Actor * _actor)
{
	m_transform.m_rotate = targetDirection(*_actor);
	m_transform.translate_front(0.08f);
}


void Enemy::look_at(CameraController* _camera, Player* _player)
{
	GSvector3 target = m_transform.m_translate;
	_player->look_at(_camera, &target);
}

void Enemy::think(Player * _player)
{
	if (m_state == ESTATE::DAMAGE || m_state == ESTATE::ATTACK || m_state == ESTATE::SPAWN)return;

	float distance = distanceActor(*_player);
	if (isNear(distance))
	{
		m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::SLIDE), true, true);
		m_state = ESTATE::SLIDE;
		slide(_player);
		return;
	}
	m_animatorOne.changeAnimation(static_cast<unsigned int>(ENEMY_ANIMATION::RUN), true, true);
	move(_player);
	m_state = ESTATE::MOVE;
}
