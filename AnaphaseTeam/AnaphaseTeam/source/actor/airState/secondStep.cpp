/**
* @file secondStep.cpp
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#include "../../../header/actor/airstate/secondStep.h"
const float secondStep::SecondStepPow = 1.0f;
secondStep::secondStep()
{

}

secondStep::~secondStep()
{

}

void secondStep::airAction(jumpControl* _jumpAction)
{
	_jumpAction->start(SecondStepPow);
}