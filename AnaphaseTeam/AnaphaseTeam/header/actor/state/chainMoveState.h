/**
* @file chainMoveState.h
* @brief ���ړ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IActionState.h"

class chainMoveState :public IActionState
{
public:
	chainMoveState();
	~chainMoveState();
	void action(ICharacter* _actor, float deltatime);
};