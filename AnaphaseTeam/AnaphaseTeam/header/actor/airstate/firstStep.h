/**
* @file firstStep.h
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class FirstStep:public IAirState
{
public:
	FirstStep();
	~FirstStep();
	void start(JumpControl* _jumpAction);
	void airAction(JumpControl* _jumpAction, Player* _player, float deltaTime);
	void next(JumpControl* _control);
private:
	static const float FirstStepPow;
};