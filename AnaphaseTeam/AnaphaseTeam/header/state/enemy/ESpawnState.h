#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"
class Enemy::ESpawnState : public ActorState<Enemy>
{
public:
	Enemy::ESpawnState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	ESpawnState * clone() const override;
};