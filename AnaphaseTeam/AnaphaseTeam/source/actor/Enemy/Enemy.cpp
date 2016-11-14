#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/renderer/Renderer.h"
#include "../../../header/collision/EnemyCollision.h"
#include "../../../header/math/Random.h"
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
	//m_animator.start(Animation(static_cast<GSuint>(ENEMY_ANIMATION::SPAWN)));
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
	_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::ENEMY, m_transform, m_animatorOne, m_Color);
}

void Enemy::collisionChase(EnemyCollision * _collision)
{
	_collision->chase(m_transform.m_translate);
}

void Enemy::damage(Player * _player)
{
	if (!isDamageState())return;
	m_state = ESTATE::DAMAGE;
	//m_animator.start(Animation(static_cast<GSuint>(ENEMY_ANIMATION::DAMAGE)));
	m_transform.translate_front(-0.1f);
}

void Enemy::state()
{
	//Math::Random rand;
	switch (m_state)
	{
	case ESTATE::SPAWN:
		/*if (m_animator.isEnd())
		{
			m_state = STATE::STAND;
			m_animator.start(Animation(static_cast<GSuint>(ENEMY_ANIMATION::IDEL), true));
		}*/
		break;
	case ESTATE::STAND:

		/*if (rand(0, 120) == 0)
		{
			m_state = STATE::MOVE;
			m_animator.start(Animation(static_cast<GSuint>(ENEMY_ANIMATION::WALK), true));
		}*/
		break;
	case ESTATE::MOVE:
		/*if (rand(0, 120) == 0)
		{
			m_state = STATE::STAND;
			m_animator.start(Animation(static_cast<GSuint>(ENEMY_ANIMATION::IDEL), true));
		}*/
		//m_transform.translate_front(1.0f);
		break;
	case ESTATE::ATTACK:
		break;
	case ESTATE::DAMAGE:
		/*if (m_animator.isEnd())
		{
			m_state = STATE::STAND;
			m_animator.start(Animation(static_cast<GSuint>(ENEMY_ANIMATION::IDEL), true));
		}*/
		break;
	}
}

const bool Enemy::isDamageState() const
{
	return m_state == ESTATE::STAND || m_state == ESTATE::MOVE || m_state == ESTATE::ATTACK;
}
