/**
* @file firstStep.cpp
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
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