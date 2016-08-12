#include "../../header/actor/JumpState.h"
#include "../../header/actor/ICharacter.h"
#include "../../header/actor/Player/Player.h"
JumpState::JumpState()
{
}

JumpState::~JumpState()
{
}

void JumpState::action(ICharacter* _actor, float deltatime)
{
	_actor->jump();
}