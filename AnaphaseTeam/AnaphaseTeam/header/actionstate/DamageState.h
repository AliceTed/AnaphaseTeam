/**
* @file DamageState.h
* @brief �_���[�W����������Ԃ̃X�e�[�g
* @author �a�J�m��
* @date 2016/11/12
*/
#pragma once

#include "IActionState.h"

class DamageState :public IActionState
{
public:
	DamageState();
	~DamageState();
	void action(ICharacter* _actor, float deltatime);
};