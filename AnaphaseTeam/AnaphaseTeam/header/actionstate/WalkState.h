/**
* @file WalkState.h
* @brief �����̃X�e�[�g
* @author �a�J�m��
* @date 2016/09/20
*/
#pragma once
#include "../actionstate/IActionState.h"
class WalkState :public IActionState
{
public:
	WalkState();
	~WalkState();
	void action(ICharacter* _actor, float deltatime);
};