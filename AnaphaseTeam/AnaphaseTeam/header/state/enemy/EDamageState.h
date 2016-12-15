#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
class Goblin::EDamageState : public ActorState<Goblin>
{
public:
	Goblin::EDamageState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDamageState * clone() const override;
};