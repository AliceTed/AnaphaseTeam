#pragma once
#include "IActionState.h"
class MoveState:public IActionState
{
public:
	MoveState();
	~MoveState();
	void action(ICharacter* _actor,float deltatime);
};