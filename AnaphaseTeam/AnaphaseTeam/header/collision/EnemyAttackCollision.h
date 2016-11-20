#pragma once
#include "CollisionActor.h"
class AttackIncidence;
class Enemy;
class EnemyAttackCollision:public CollisionActor
{
public:
	EnemyAttackCollision(const AttackIncidence* _point);
	~EnemyAttackCollision();
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(const Renderer& _renderer)override;
private:
	const AttackIncidence* m_point;
};