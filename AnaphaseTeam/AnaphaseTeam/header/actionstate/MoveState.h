/**
* @file MoveState.h
* @brief �ړ��̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "../actionstate/IActionState.h"
class MoveState:public IActionState
{
public:
	MoveState();
	~MoveState();
	void action(ICharacter* _actor,float deltatime);
};