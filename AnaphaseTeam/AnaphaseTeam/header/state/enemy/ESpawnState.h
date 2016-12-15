#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
class Goblin::ESpawnState : public ActorState<Goblin>
{
public:
	Goblin::ESpawnState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	ESpawnState * clone() const override;
};