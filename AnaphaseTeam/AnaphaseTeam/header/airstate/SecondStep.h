/**
* @file secondStep.h
* @brief ��i�W�����v�ڂ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class SecondStep:public IAirState
{
public:
	SecondStep(JumpControl* _control, Player* _player);
	~SecondStep();
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̗͂̐ݒ�
	*/
	void start();
	/**
	* @brief �W�����v�̈ړ�����
	*/
	void update(float deltaTime);
	const bool isEnd() const;
	std::shared_ptr<IAirState> next() const;
private:
	void change();
private:
	float m_JumpPower;
	static const float SecondStepPow;
	bool m_isEnd;
	AirAction_Ptr m_next;
	JumpControl* m_control;
	Player* m_player;
};