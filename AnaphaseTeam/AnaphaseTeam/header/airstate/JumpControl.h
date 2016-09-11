#pragma once
/**
* @file jumpControl.h
* @brief �W�����v�̐���
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include<gslib.h>
#include <memory>
class Player;
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class JumpControl
{
public:
	JumpControl();
	~JumpControl();
	void update(Player* _player, float deltaTime);
	/**
	* @fn
	* @brief ���n
	*/
	void groundHit();
	/**
	* @fn
	* @brief �W�����v�͐ݒ�
	*/
	void jumping(Player* _player, float deltaTime);
	/**
	* @fn
	* @brief �eairState����Ԃ��Ă����W�����v�͂�ݒ�
	*/
	void start(const float _jumpStepPows);
	/**
	* @fn
	* @brief airState��؂�ւ���
	*/
	void airActionChange(AirAction_Ptr _airAction);
	/**
	* @fn
	* @brief �W�����v�Ɋւ��Ă̎��̃G�A�A�N�V�����X�e�[�g�̐؂�ւ�
	*/
	void jump();

private:
	float m_JumpPower;
	float m_Acceleration;
	static const float MaxJumpPower;
	AirAction_Ptr m_airAction;
};