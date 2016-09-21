/**
* @file AttackState.h
* @brief ジャンプのステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IActionState.h"
class JumpState :public IActionState
{
public:
	JumpState();
	~JumpState();
	void action(ICharacter* _actor, float deltatime);
};