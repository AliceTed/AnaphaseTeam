#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::EDeadState : public ActorState<Enemy>
{
public:
	Enemy::EDeadState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDeadState * clone() const override;
};
