#include "../../header/actionstate/MoveState.h"
#include "../../header/actor/ICharacter.h"


MoveState::MoveState()
{
}

MoveState::~MoveState()
{
}

void MoveState::action(ICharacter* _actor,float deltaTime)
{
	_actor->move(deltaTime);
}