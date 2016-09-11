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
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̗͂̐ݒ�
	*/
	void start(JumpControl* _control);
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̈ٓ�����
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
	/**
	* @fn
	* @brief ����airState��SecondStep�ɂ���
	*/
	void next(JumpControl* _control);
private:
	static const float FirstStepPow;
};