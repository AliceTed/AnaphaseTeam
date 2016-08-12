#include "../../header/actor/StandState.h"
#include "../../header/actor/Actor.h"
StandState::StandState()
{}
StandState::~StandState()
{}
void StandState::action(Actor* _actor,float deltatime)
{
	_actor->stand();
}