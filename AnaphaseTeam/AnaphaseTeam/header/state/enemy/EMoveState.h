#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"
class Goblin::EMoveState : public ActorState<Goblin>
{
public:
	Goblin::EMoveState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EMoveState * clone() const override;
private:
};