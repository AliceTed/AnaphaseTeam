/**
* @file firstStep.h
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class FirstStep:public IAirState
{
public:
	FirstStep();
	~FirstStep();
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̗͂̐ݒ�
	*/
	void start(JumpControl* _control, Player* _player);
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̈ٓ�����
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
private:
	void change(JumpControl* _control, Player* _player);
	AirAction_Ptr next(const Player* _player) const;
private:
	float m_JumpPower;
	static const float FirstStepPow;
};