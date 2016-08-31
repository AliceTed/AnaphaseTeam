/**
* @file groundState.h
* @brief �n��ɂ���Ƃ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class groundState:public IAirState
{
public:
	groundState();
	~groundState();
	void start(jumpControl* _jumpAction);
	void airAction(jumpControl* _jumpAction, Player* _player, float deltaTime);
	void next(jumpControl* _control);
};