#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
#include "convenient\Timer.h"
#include<functional>
class Goblin::EDownState : public ActorState<Goblin>
{
public:
	Goblin::EDownState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EDownState * clone() const override;
	void stand(float deltaTime);
	void down(float deltaTime);
private:
	Timer m_timer;
	bool m_standStart;
	void (Goblin::EDownState::*actionPtr)(float);
};