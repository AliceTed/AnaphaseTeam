#pragma once
class Actor;
__interface IActionState
{
	void action(Actor* _actor) = 0;
};