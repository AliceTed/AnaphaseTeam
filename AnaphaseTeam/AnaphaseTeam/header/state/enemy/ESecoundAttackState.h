#pragma once
#include "../../actor/Enemy/Enemy.h"
#include "../ActorState.h"

class Enemy::ESecoundAttackState : public ActorState<Enemy>
{
public:
	Enemy::ESecoundAttackState(Enemy* _enemy);

	void start() override;
	void action(float deltaTime) override;
	ESecoundAttackState * clone() const override;
private:
	bool m_start;
	float m_timer;
};