#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::EThinkState : public ActorState<Enemy>
{
public:
	Enemy::EThinkState(Enemy* _enemy);
	void start() override;
	void action(float deltaTime) override;
	Enemy::EThinkState* clone() const override;
};