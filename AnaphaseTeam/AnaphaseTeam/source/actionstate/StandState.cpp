#include "../../header/actionstate/StandState.h"
#include "../../header/actor/ICharacter.h"
StandState::StandState()
{}
StandState::~StandState()
{}
void StandState::action(ICharacter* _actor,float deltaTime)
{
	_actor->stand(deltaTime);
}