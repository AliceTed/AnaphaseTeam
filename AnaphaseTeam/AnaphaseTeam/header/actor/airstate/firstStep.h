/**
* @file firstStep.h
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class firstStep:public IAirState
{
public:
	firstStep();
	~firstStep();
	void start(jumpControl* _jumpAction);
	void airAction(jumpControl* _jumpAction, Player* _player, float deltaTime);
	void next(jumpControl* _control);
private:
	static const float FirstStepPow;
};