#pragma once
__interface ICharacter;
__interface IActionState
{
public:
	void action(ICharacter* _actor,float deltatime) = 0;
};