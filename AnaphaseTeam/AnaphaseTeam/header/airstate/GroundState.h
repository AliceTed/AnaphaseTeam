/**
* @file groundState.h
* @brief 地上にいるときのステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "../convenient/Timer.h"
class GroundState:public IAirState
{
public:
	GroundState();
	~GroundState();
	void start(JumpControl* _control, Player* _player);
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
private:
	Timer m_RigorTimer;
};