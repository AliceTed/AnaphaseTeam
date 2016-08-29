/**
* @file AttackState.cpp
* @brief UŒ‚‚ÌƒXƒe[ƒg
* @author a’J’m÷
* @date 2016/08/29
*/
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