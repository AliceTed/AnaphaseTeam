#include "../../../header/actor/Enemy/Enemy.h"
#include "../../../header/renderer/Renderer.h"

Enemy::Enemy()
	:Actor(
		Transform({ 10,0.5f,-30 }, GSquaternion(0,0,0,0)),
		MODEL_ID::PLAYER,
		Sphere(GSvector3(0, 0, 0), 0),
		Actor_Tag::PLAYER
		)
{

}

Enemy::~Enemy()
{

}

void Enemy::initialize()
{
	Actor::initialize();
	m_animatorOne.initialize();
	m_animatorOne.changeAnimation(ANIMATION_ID::STAND, true, true);
}

void Enemy::update(float deltatime)
{
}

void Enemy::draw(const Renderer & _renderer, const Camera & _camera)
{
	_renderer.getDraw3D().drawMesh_calcu(MODEL_ID::PLAYER, m_transform, m_animatorOne, m_Color);
}

void Enemy::finish()
{
}

void Enemy::stand(float deltaTime)
{
}

void Enemy::move(float deltaTime)
{
}

void Enemy::attack(float deltaTime)
	{
}

void Enemy::damage(float deltaTime)
	{
}

void Enemy::jump(float deltaTime)
		{
	}

void Enemy::avoid(float deltaTime)
	{
}

void Enemy::createColision()
	{
}
