#pragma once
#include "CollisionActor.h"
#include "../convenient/Timer.h"
class AttackIncidence;
class Enemy;
class EnemyAttackCollision:public CollisionActor
{
public:
	//time‚Í•bŽw’è
	EnemyAttackCollision(const AttackIncidence* _point,float _destroytime);
	~EnemyAttackCollision();
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(IRenderer * _renderer)override;
private:
	const AttackIncidence* m_point;
	Timer m_destory_timer;
};