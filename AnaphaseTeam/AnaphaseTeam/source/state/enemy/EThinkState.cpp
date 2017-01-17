#include"state/enemy/EThinkState.h"

Goblin::EThinkState::EThinkState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::EThinkState::start()
{
}

void Goblin::EThinkState::action(float deltaTime)
{
	m_actor->directionToPlayer();
	changeState(ACTOR_STATE::ESTAND);
}

Goblin::EThinkState* Goblin::EThinkState::clone() const
{
	return new EThinkState(*this);
}
