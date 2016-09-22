#include "../../header/actionstate/AvoidState.h"
#include "../../header/actor/ICharacter.h"
AvoidState::AvoidState()
{
}

AvoidState::~AvoidState()
{
}

void AvoidState::action(ICharacter * _actor, float deltatime)
{
	_actor->avoid(deltatime);
}
