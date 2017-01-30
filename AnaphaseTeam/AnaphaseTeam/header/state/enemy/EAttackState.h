#pragma once
#include "../../actor/Enemy/Goblin.h"
#include "../../actor/Enemy/IEnemy.h"
#include "../ActorState.h"
#include "convenient\Timer.h"

class Goblin::EAttackState : public ActorState<Goblin>
{
public:
	Goblin::EAttackState(Goblin* _enemy);

	void start() override;
	void action(float deltaTime) override;
	EAttackState * clone() const override;
	void moveFront(float deltaTime);
	void collisionStart(float deltaTime);
	void finshAction(float deltaTime);
private:
	bool m_secoundAttack;
	Timer m_timer;
	std::function<void(float)> funcPtr;
};