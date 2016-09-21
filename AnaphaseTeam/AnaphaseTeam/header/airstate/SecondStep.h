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
	void start(JumpControl* _control, Player* _player);
	/**
	* @brief �W�����v�̈ړ�����
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
private:
	void change(JumpControl* _control, Player* _player);
	AirAction_Ptr next(const Player* _player) const;
private:
	float m_JumpPower;
	static const float SecondStepPow;
};