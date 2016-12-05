#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"
class Enemy::EStandState : public ActorState<Enemy>
{
public:
	Enemy::EStandState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EStandState * clone() const override;

private:
	Timer m_tiemr;

};