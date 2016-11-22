#pragma once
#include "CollisionActor.h"
#include "../../header/convenient/Timer.h"
class PlayerAttackCollision:public CollisionActor
{
public:
	PlayerAttackCollision(const GSvector3& _position,float _deadtime,float _speed);
	~PlayerAttackCollision();
private:
	void doUpdate(float deltaTime);
	void doDraw(const Renderer& _renderer);
	void collision_Enter(HitInformation& _hit);
private:
	Timer m_destroy;
	float m_speed;
};