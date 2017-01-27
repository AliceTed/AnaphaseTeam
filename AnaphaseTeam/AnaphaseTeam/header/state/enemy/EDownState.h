#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
class Goblin::EDownState : public ActorState<Goblin>
{
public:
	Goblin::EDownState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDownState * clone() const override;
};