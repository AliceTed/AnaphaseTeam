/**
* @file firstStep.h
* @brief 硬直落下ステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class RestrictionFall :public IAirState
{
public:
	RestrictionFall();
	~RestrictionFall();
	void airAction(jumpControl* _jumpAction);
};
