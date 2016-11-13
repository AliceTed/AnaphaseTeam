/**
* @file DamageState.cpp
* @brief 立ち状態のステート
* @author 渋谷知樹
* @date 2016/11/12
*/
#include "../../header/actionstate/DamageState.h"
#include "../../header/actor/ICharacter.h"

DamageState::DamageState()
{
}

DamageState::~DamageState()
{
}

void DamageState::action(ICharacter * _actor, float deltatime)
{
	_actor->damage(deltatime);
}
