#include "../../../header/actor/state/JumpState.h"
#include "../../../header/actor/ICharacter.h"
JumpState::JumpState()
{
}

JumpState::~JumpState()
{
}

void JumpState::action(ICharacter* _actor, float deltaTime)
{
	_actor->jump(deltaTime);
}