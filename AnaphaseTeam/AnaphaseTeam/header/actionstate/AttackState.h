#pragma once
#include "IActionState.h"
class AttackState :public IActionState
{
public:
	AttackState();
	~AttackState();
	void action(ICharacter* _actor, float deltatime);
};