#pragma once
#include "IActionState.h"
class AvoidState:public IActionState
{
public:
	AvoidState();
	~AvoidState();
	void action(ICharacter* _actor, float deltatime);
};