//#include "../../actor/state/AttackState.h"
#include "../../header/actionstate/AttackState.h"
#include "../../header/actor/ICharacter.h"


AttackState::AttackState()
{
}

AttackState::~AttackState()
{
}

void AttackState::action(ICharacter* _actor, float deltaTime)
{
	_actor->attack(deltaTime);
}