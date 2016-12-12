#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::EMoveBackState : public ActorState<Enemy>
{
public:
	Enemy::EMoveBackState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EMoveBackState * clone() const override;
private:
};