#include "../../header/actor/AttackState.h"
#include "../../header/actor/ICharacter.h"


AttackState::AttackState()
{
}

AttackState::~AttackState()
{
}

void AttackState::action(ICharacter* _actor, float deltatime)
{
	_actor->attack(deltatime);
}