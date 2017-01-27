#include "state\enemy\EDownState.h"
Goblin::EDownState::EDownState(Goblin* _enemy)
	:ActorState(_enemy)
{

}

void Goblin::EDownState::start()
{
}

void Goblin::EDownState::action(float deltaTime)
{
}

Goblin::EDownState * Goblin::EDownState::clone() const
{
	return new EDownState(*this);
}