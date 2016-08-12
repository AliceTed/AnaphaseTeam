#pragma once
#include "IActionState.h"
class MoveState:public IActionState
{
	MoveState();
	~MoveState();
	void action(Actor* actor);
};