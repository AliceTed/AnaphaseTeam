/**
* @file AttackState.h
* @brief �U���̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once
#include "IActionState.h"
class AttackState :public IActionState
{
public:
	AttackState();
	~AttackState();
	void action(ICharacter* _actor, float deltatime);
};