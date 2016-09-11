/**
* @file firstStep.h
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
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