#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::ESlideState : public ActorState<Enemy>
{
public:
	Enemy::ESlideState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	ESlideState * clone() const override;
};