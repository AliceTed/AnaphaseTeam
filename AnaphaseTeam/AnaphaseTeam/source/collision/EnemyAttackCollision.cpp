#include "..\..\header\collision\EnemyAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/attack/AttackStatus.h"
#include "../../header/collision/HitInformation.h"
Enemy::EnemyAttackCollision::EnemyAttackCollision(const GSvector3& _point, float _destroytime)
	:CollisionActor(new Sphere(_point,0.5f),Collision_Tag::ENEMY_ATTACK),
	m_point(_point),
	m_destory_timer(_destroytime)
{
}

Enemy::EnemyAttackCollision::~EnemyAttackCollision()
{
}

void Enemy::EnemyAttackCollision::doUpdate(float deltaTime)
{
	m_destory_timer.update(deltaTime);
	if (m_destory_timer.isEnd())
	{
		destroy();
	}
}

void Enemy::EnemyAttackCollision::collision_Enter(HitInformation & _hit)
{	
	if (_hit.m_tag != Collision_Tag::PLAYER)return;
	Actor* act = _hit.m_parent;
	AttackStatus attackStatus;
	attackStatus.m_power = 10;
	act->damage(attackStatus);
}

void Enemy::EnemyAttackCollision::doDraw(IRenderer * _renderer)
{
	//m_shape->draw(_renderer);
}
