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
	void start(JumpControl* _jumpAction);
	void airAction(JumpControl* _jumpAction, Player* _player, float deltaTime);
	void next(JumpControl* _control);
private:
	Timer m_RigorTimer;
};