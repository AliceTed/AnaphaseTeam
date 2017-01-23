#pragma once
#include "CollisionActor.h"
#include "../actor/Player/Player.h"
#include "../convenient/Timer.h"
#include "../actor/Enemy/IEnemy.h"

class IEnemy::EnemyAttackCollision:public CollisionActor
{
public:
	//time‚Í•bŽw’è
	IEnemy::EnemyAttackCollision(IEnemy* _ienemy, const GSvector3& _point,float _destroytime);
private:
	void doUpdate(float deltaTime)override;
	void collision_Enter(HitInformation& _hit)override;
	void doDraw(IRenderer * _renderer)override;

private:
	IEnemy* m_ienemy;
	GSvector3 m_point;
	Timer m_destory_timer;
	
};