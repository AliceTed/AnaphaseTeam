#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
class Goblin::EThinkState : public ActorState<Goblin>
{
public:
	Goblin::EThinkState(Goblin* _enemy);
	void start() override;
	void action(float deltaTime) override;
	Goblin::EThinkState* clone() const override;
};