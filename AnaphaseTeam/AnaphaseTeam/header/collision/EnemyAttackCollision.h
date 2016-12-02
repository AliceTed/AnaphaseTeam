#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
#include "../convenient/Timer.h"
class Enemy;
class EnemyAttackCollision:public CollisionActor
{
public:
	//time‚Í•bŽw’è
	EnemyAttackCollision(const GSvector3& _point,float _destroytime);
	~EnemyAttackCollision();
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(IRenderer * _renderer)override;

private:
	GSvector3 m_point;
	Timer m_destory_timer;
};