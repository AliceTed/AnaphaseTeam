#pragma once
#include "../actor/state/IActionState.h"
class JumpState :public IActionState
{
public:
	JumpState();
	~JumpState();
	void action(ICharacter* _actor, float deltatime);
};