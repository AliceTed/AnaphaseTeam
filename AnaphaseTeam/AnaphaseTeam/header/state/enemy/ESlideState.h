#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
#include "../../convenient/Timer.h"
class Goblin::ESlideState : public ActorState<Goblin>
{
public:
	Goblin::ESlideState(Goblin* _enemy);
	void start() override;
	void action(float deltaTime) override;
	ESlideState * clone() const override;
private:
	Timer m_timer;
};