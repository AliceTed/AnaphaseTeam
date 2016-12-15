#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
class Goblin::EDeadState : public ActorState<Goblin>
{
public:
	Goblin::EDeadState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDeadState * clone() const override;
};
