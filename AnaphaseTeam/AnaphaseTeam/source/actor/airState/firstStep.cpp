/**
* @file firstStep.cpp
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/firstStep.h"

const float firstStep::FirstStepPow = 1.2f;
firstStep::firstStep()
{

}

firstStep::~firstStep()
{

}

void firstStep::airAction(jumpControl* _jumpAction)
{
	_jumpAction->start(FirstStepPow);
}