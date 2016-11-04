#pragma once

#include "IInputPattern.h"
class Input;
class InputPattern_A :public IInputPattern
{
public:
	InputPattern_A(Input* _input);
	~InputPattern_A();
public://ˆÚ“®
	   //…•½,‚’¼
	const GSvector2 velocity();
	const bool move();
	const bool walk();
public://ƒAƒNƒVƒ‡ƒ“
	const bool jump();
	const bool attack();
	const bool scythe();
	const bool charge();
	const bool gun();
	const bool avoid();
	const bool gaugeAttack1();
	const bool gaugeAttack2();
	const bool gaugeAttack3();
public:
	const bool up();
	const bool down();
	const bool right();
	const bool left();
	const bool exit();
public:
	const bool reset();
private:
	Input* m_input;
};