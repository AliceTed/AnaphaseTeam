/**
* @file secondStep.h
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
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