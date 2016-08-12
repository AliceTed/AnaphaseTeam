#include "../../header/actor/MoveState.h"
#include "../../header/actor/ICharacter.h"


MoveState::MoveState()
{
}

MoveState::~MoveState()
{
}

void MoveState::action(ICharacter* _actor,float deltatime)
{
	_actor->move();
}