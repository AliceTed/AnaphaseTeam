/**
* @file secondStep.h
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/

#pragma once
#include "IAirState.h"
#include "jumpControl.h"

class SecondStep:public IAirState
{
public:
	SecondStep();
	~SecondStep();
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̗͂̐ݒ�
	*/
	void start(JumpControl* _control);
	/**
	* @brief �W�����v�̈ړ�����
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
	void next(JumpControl* _control);
private:
	static const float SecondStepPow;
};