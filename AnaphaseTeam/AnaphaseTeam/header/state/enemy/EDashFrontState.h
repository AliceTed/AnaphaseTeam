#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::EDashFrontState : public ActorState<Enemy>
{
public:
	Enemy::EDashFrontState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDashFrontState * clone() const override;
};