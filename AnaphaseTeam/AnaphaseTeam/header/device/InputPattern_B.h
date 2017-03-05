#pragma once
#include "IInputPattern.h"
class Input;
class InputPattern_B :public IInputPattern
{
public:
	InputPattern_B(Input* _input);
	~InputPattern_B();
public:
	const GSvector2 velocity();
	const bool move();
	const bool walk();
public://ƒAƒNƒVƒ‡ƒ“
	const bool jump();
	const bool attack();
	const bool slowAttackTrigger();
	const bool quickAttackTrigger();
	const bool avoid();
	const bool gaugeAttack1();
	const bool gaugeAttack2();
	const bool gaugeAttack3();
	const bool lockOn();

	const bool specialSkillMode();
public:
	const bool up();
	const bool down();
	const bool right();
	const bool left();
	const bool exit();
public:
	const bool reset();
	const bool decision();
private:
	Input* m_input;
};