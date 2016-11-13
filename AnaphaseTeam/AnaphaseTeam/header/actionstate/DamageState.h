/**
* @file DamageState.h
* @brief ダメージをうけた状態のステート
* @author 渋谷知樹
* @date 2016/11/12
*/
#pragma once

#include "IActionState.h"

class DamageState :public IActionState
{
public:
	DamageState();
	~DamageState();
	void action(ICharacter* _actor, float deltatime);
};