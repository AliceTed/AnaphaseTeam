/**
* @file StandState.cpp
* @brief 立ち状態のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
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