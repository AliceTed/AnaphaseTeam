/**
* @file chainMoveState.h
* @brief 鎖移動のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IActionState.h"

class chainMoveState :public IActionState
{
public:
	chainMoveState();
	~chainMoveState();
	void action(ICharacter* _actor, float deltatime);
};