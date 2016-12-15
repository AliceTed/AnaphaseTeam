#pragma once
#include "CollisionActor.h"
#include "../actor/Enemy/IEnemy.h"
class IEnemy::EnemyCollision:public CollisionActor
{
public:
	IEnemy::EnemyCollision(IEnemy* _enemy);
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(IRenderer * _renderer)override;
private:
	IEnemy* m_enemy;
	GSvector3 m_position;
};
