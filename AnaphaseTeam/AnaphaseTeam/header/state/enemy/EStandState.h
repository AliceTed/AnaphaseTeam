#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"
class Goblin::EStandState : public ActorState<Goblin>
{
public:
	Goblin::EStandState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EStandState * clone() const override;

private:
	Timer m_tiemr;
};