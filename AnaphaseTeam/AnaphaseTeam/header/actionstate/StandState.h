/**
* @file StandState.h
* @brief ������Ԃ̃X�e�[�g
* @author �a�J�m��
* @date 2016/08/29
*/
#pragma once

#include "IActionState.h"

class StandState :public IActionState
{
public:
	StandState();
	~StandState();
	void action(ICharacter* _actor, float deltatime);
};