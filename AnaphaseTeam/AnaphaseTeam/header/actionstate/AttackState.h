/**
* @file AttackState.h
* @brief 攻撃のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IActionState.h"
class AttackState :public IActionState
{
public:
	AttackState();
	~AttackState();
	void action(ICharacter* _actor, float deltatime);
};