/**
* @file RigorState.h
* @brief 着地硬直時のステート
* @author 渋谷知樹
* @date 2016/08/29
*/

#pragma once
#include "IAirState.h"
#include "jumpControl.h"
#include "../convenient/Timer.h"

class RigorState :public IAirState
{
public:
	RigorState();
	~RigorState();
	void start(JumpControl* _jumpAction);
	void airAction(JumpControl* _jumpAction, Player* _player, float deltaTime);
	void next(JumpControl* _control);
private:
	Timer m_RigorTimer;
};