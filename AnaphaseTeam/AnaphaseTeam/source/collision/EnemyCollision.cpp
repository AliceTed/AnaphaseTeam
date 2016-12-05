#include "../../header/collision/EnemyCollision.h"
#include "../../header/actor/Enemy/Enemy.h"
#include "../../header/shape/Capsule.h"
#include "../../header/collision/HitInformation.h"
#include "../../header/actor/Player/Player.h"
Enemy::EnemyCollision::EnemyCollision(Enemy * _enemy)
	:CollisionActor(new Capsule(Segment(GSvector3(0, 0.2f, 0), GSvector3(0, 1.2f, 0)), 0.4f), Collision_Tag::ENEMY),
	m_enemy(_enemy)
{
}

void Enemy::EnemyCollision::doUpdate(float deltaTime)
{
 	m_shape->transfer(m_enemy->m_transform.m_translate);
}

void Enemy::EnemyCollision::collision_Enter(HitInformation & _hit)
{
	if (_hit.m_tag == Collision_Tag::PLAYER_SPECIALATTACK)
	{
		m_enemy->specialDamage();
		return;
	}
}

void Enemy::EnemyCollision::doDraw(IRenderer * _renderer)
{
	//m_shape->draw(_renderer);
}
