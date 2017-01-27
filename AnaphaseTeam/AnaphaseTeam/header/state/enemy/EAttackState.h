#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../../actor/Enemy/IEnemy.h"
#include "../ActorState.h"
#include "convenient\Timer.h"

class Goblin::EAttackState : public ActorState<Goblin>
{
public:
	Goblin::EAttackState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EAttackState * clone() const override;
	void collisionStart();
private:
	bool m_secoundAttack;
	bool m_attack;
	Timer m_timer;
};