#pragma once
#include "IInputPattern.h"
class Input;
class InputPattern_B
{
public:
	InputPattern_B(Input* _input);
	~InputPattern_B();
public://移動
	   //水平,垂直
	const GSvector2 velocity();
	const bool move();
	const bool walk();
public://アクション
	const bool jump();
	const bool attack();
	const bool scythe();
	const bool gun();
	const bool avoid();
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