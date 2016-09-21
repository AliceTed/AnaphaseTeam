/**
* @file groundState.h
* @brief �n��ɂ���Ƃ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class GroundState:public IAirState
{
public:
	GroundState();
	~GroundState();
	void start(JumpControl* _control);
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
	/**
	* @fn
	* @brief �n�ʂɂ���Ƃ��A����airstate��FirstStep�ɂ���
	*/
	void next(JumpControl* _control);
};