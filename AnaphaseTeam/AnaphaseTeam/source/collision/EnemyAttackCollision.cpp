#include "..\..\header\collision\EnemyAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/attack/AttackIncidence.h"
EnemyAttackCollision::EnemyAttackCollision(const GSvector3& _point, float _destroytime)
	:CollisionActor(new Sphere(_point,0.5f),Collision_Tag::ENEMY_ATTACK),
	m_point(_point),
	m_destory_timer(_destroytime)
{
}

EnemyAttackCollision::~EnemyAttackCollision()
{
}

void EnemyAttackCollision::doUpdate(float deltaTime)
{
	m_destory_timer.update(deltaTime);
	if (m_destory_timer.isEnd())
	{
		destroy();
	}
}

void EnemyAttackCollision::collision_Enter(HitInformation & _hit)
{
}

void EnemyAttackCollision::doDraw(const Renderer & _renderer)
{
	//m_shape->draw(_renderer);
}
