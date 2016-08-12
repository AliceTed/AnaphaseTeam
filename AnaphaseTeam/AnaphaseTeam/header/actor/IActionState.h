#pragma once
class Actor;
__interface IActionState
{
	void action(Actor* actor) = 0;
};