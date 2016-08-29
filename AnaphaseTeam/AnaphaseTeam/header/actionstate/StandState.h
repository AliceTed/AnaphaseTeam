/**
* @file StandState.h
* @brief 立ち状態のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once

#include "IActionState.h"

class StandState :public IActionState
{
public:
	StandState();
	~StandState();
	void action(ICharacter* _actor, float deltatime);
};