#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../ActorState.h"

class Goblin::ESecoundAttackState : public ActorState<Goblin>
{
public:
	Goblin::ESecoundAttackState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	ESecoundAttackState * clone() const override;
private:
	bool m_start;
	float m_timer;
};