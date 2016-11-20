#include "..\..\header\collision\EnemyAttackCollision.h"
#include "../../header/shape/Sphere.h"
#include "../../header/attack/AttackIncidence.h"
EnemyAttackCollision::EnemyAttackCollision(const AttackIncidence * _point)
	:CollisionActor(new Sphere(GSvector3(0,0,0),1),Collision_Tag::ENEMY_ATTACK),
	m_point(_point)
{
}

EnemyAttackCollision::~EnemyAttackCollision()
{
}

void EnemyAttackCollision::doUpdate(float deltaTime)
{
	m_shape->transfer(m_point->point());
}

void EnemyAttackCollision::collision_Enter(HitInformation & _hit)
{
}

void EnemyAttackCollision::doDraw(const Renderer & _renderer)
{
	//m_shape->draw(_renderer);
}
