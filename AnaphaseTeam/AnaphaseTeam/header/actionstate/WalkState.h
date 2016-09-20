/**
* @file WalkState.h
* @brief 歩きのステート
* @author 渋谷知樹
* @date 2016/09/20
*/
#pragma once
#include "../actionstate/IActionState.h"
class WalkState :public IActionState
{
public:
	WalkState();
	~WalkState();
	void action(ICharacter* _actor, float deltatime);
};