#include "../../header/actor/MoveState.h"
#include "../../header/actor/Actor.h"


MoveState::MoveState()
{
}

MoveState::~MoveState()
{
}

void MoveState::action(Actor* _actor)
{
	_actor->move();
}