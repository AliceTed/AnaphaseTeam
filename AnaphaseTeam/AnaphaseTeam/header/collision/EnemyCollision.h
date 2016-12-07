#pragma once
#include "CollisionActor.h"
#include "../actor/Enemy/Enemy.h"
class Enemy::EnemyCollision:public CollisionActor
{
public:
	Enemy::EnemyCollision(Enemy* _enemy);
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(IRenderer * _renderer)override;
private:
	Enemy* m_enemy;
	GSvector3 m_position;
};
