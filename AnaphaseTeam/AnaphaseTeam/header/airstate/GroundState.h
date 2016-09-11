/**
* @file groundState.h
* @brief 地上にいるときのステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class GroundState:public IAirState
{
public:
	GroundState();
	~GroundState();
	void start(JumpControl* _jumpAction);
	void airAction(JumpControl* _jumpAction, Player* _player, float deltaTime);
	void next(JumpControl* _control);
};