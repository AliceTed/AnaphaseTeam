#pragma once
#include "IActionState.h"
class JumpState :public IActionState
{
public:
	JumpState();
	~JumpState();
	void action(ICharacter* _actor, float deltatime);
};