/**
* @file RigorState.h
* @brief ���n�d�����̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/

#pragma once
#include "IAirState.h"
#include "jumpControl.h"
#include "../convenient/Timer.h"

class RigorState :public IAirState
{
public:
	RigorState();
	~RigorState();
	/**
	* @fn
	* @brief ���n�d���̎��Ԃ̐ݒ�
	*/
	void start(JumpControl* _control);
	/**
	* @fn
	* @brief ���n�̃A�j���[�V�����ƒ��n���̍d��
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
	void next(JumpControl* _control);
private:
	Timer m_RigorTimer;
};