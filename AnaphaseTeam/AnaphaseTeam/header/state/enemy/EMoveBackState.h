#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
class Goblin::EMoveBackState : public ActorState<Goblin>
{
public:
	Goblin::EMoveBackState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EMoveBackState * clone() const override;
private:
};