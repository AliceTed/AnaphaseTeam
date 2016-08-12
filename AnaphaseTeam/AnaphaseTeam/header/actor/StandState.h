#pragma once

#include "IActionState.h"

class StandState :public IActionState
{
	StandState();
	~StandState();
	void action(Actor* _actor, float deltatime);
};