/**
* @file secondStep.h
* @brief 二段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/

#pragma once
#include "IAirState.h"
#include "jumpControl.h"

class secondStep:public IAirState
{
public:
	secondStep();
	~secondStep();
	void airAction(jumpControl* _jumpAction);
private:
	static const float SecondStepPow;
};