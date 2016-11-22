/**
* @file MoveState.h
* @brief 移動のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "../actionstate/IActionState.h"
class MoveState:public IActionState
{
public:
	MoveState();
	~MoveState();
	void action(ICharacter* _actor,float deltatime);
};