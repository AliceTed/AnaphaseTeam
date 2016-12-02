#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"

class Enemy::EAttackState : public ActorState<Enemy>
{
public:
	Enemy::EAttackState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EAttackState * clone() const override;

};