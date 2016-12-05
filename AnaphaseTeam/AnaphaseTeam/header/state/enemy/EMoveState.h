#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::EMoveState : public ActorState<Enemy>
{
public:
	Enemy::EMoveState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EMoveState * clone() const override;
};