/**
* @file firstStep.h
* @brief �d�������X�e�[�g
* @author �a�J�m��
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
	void start(JumpControl* _jumpAction);
	void airAction(JumpControl* _jumpAction, Player* _player, float deltaTime);
	void next(JumpControl* _control);
};
