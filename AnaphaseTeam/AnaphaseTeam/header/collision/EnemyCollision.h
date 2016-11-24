#pragma once
#include "CollisionActor.h"
class Enemy;
class EnemyCollision:public CollisionActor
{
public:
	EnemyCollision(Enemy* _enemy);
	~EnemyCollision();
	void chase(const GSvector3& _position);
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(IRenderer * _renderer)override;
private:
	Enemy* m_enemy;
	GSvector3 m_position;
};
