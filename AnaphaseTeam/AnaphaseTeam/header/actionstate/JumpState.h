/**
* @file AttackState.h
* @brief �W�����v�̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IActionState.h"
class JumpState :public IActionState
{
public:
	JumpState();
	~JumpState();
	void action(ICharacter* _actor, float deltatime);
};