#include "../../header/actor/StandState.h"
#include "../../header/actor/ICharacter.h"
StandState::StandState()
{}
StandState::~StandState()
{}
void StandState::action(ICharacter* _actor,float deltatime)
{
	_actor->stand();
}