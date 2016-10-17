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
	FirstStep(JumpControl* _control, Player* _player);
	~FirstStep();
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̗͂̐ݒ�
	*/
	void start();
	/**
	* @fn
	* @brief ��i�ڂ̃W�����v�̈ٓ�����
	*/
	void update(float deltaTime);
	const bool isEnd() const;
	std::shared_ptr<IAirState> next() const;
private:
	void change();
private:
	JumpControl * m_control;
	Player * m_player;
	float m_JumpPower;
	static const float FirstStepPow;
	bool m_isEnd;
	AirAction_Ptr m_next;
};