#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::EDamageState : public ActorState<Enemy>
{
public:
	Enemy::EDamageState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDamageState * clone() const override;
};