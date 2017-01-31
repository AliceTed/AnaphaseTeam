#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"
#include "convenient\Timer.h"
class Goblin::ESecoundAttackState : public ActorState<Goblin>
{
public:
	Goblin::ESecoundAttackState(Goblin* _enemy);
	void start() override;
	void action(float deltaTime) override;
	ESecoundAttackState * clone() const override;
private:
	void collisionStart(float deltaTime);
	void finishAction(float deltaTime);
private:
	Timer m_timer;
	std::function<void(float)> funcPtr;
};