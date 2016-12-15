#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"
class Goblin::EDashFrontState : public ActorState<Goblin>
{
public:
	Goblin::EDashFrontState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDashFrontState * clone() const override;
};