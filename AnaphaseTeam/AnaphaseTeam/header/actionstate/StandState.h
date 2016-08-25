#pragma once

#include "IActionState.h"

class StandState :public IActionState
{
public:
	StandState();
	~StandState();
	void action(ICharacter* _actor, float deltatime);
};