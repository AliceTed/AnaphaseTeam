#include "..\..\header\collision\PlayerAttackCollision.h"
#include "../../header/shape/Sphere.h"
PlayerAttackCollision::PlayerAttackCollision(const GSvector3& _position,float _deadtime, float _speed)
	:CollisionActor(new Sphere(_position,0.7f),Collision_Tag::PLAYER_WEAPON),
	m_destroy(_deadtime),m_speed(_speed)
{
}

PlayerAttackCollision::~PlayerAttackCollision()
{
}

void PlayerAttackCollision::doUpdate(float deltaTime)
{
	m_destroy.update(deltaTime*m_speed);
	if (m_destroy.isEnd())
	{
		destroy();
	}
}

void PlayerAttackCollision::doDraw(const Renderer & _renderer)
{
	//m_shape->draw(_renderer);
}

void PlayerAttackCollision::collision_Enter(HitInformation & _hit)
{
}
