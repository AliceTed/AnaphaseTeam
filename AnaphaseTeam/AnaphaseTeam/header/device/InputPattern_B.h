#pragma once
#include "IInputPattern.h"
class Input;
class InputPattern_B
{
public:
	InputPattern_B(Input* _input);
	~InputPattern_B();
public://ˆÚ“®
	   //…•½,‚’¼
	const GSvector2 velocity();
	const bool move();
	const bool walk();
public://ƒAƒNƒVƒ‡ƒ“
	const bool jump();
	const bool attack();
	const bool scythe();
	const bool gun();
	const bool avoid();
public:
	const bool up();
	const bool down();
	const bool exit();
private:
	Input* m_input;
};