#pragma once

#include "IInputPattern.h"
class Input;
class InputPattern_A :public IInputPattern
{
public:
	InputPattern_A(Input* _input);
	~InputPattern_A();
public://移動
	   //水平,垂直
	const GSvector2 velocity();
	const bool move();
	const bool walk();
public://アクション
	const bool jump();
	const bool attack();
	const bool slowAttackTrigger();
	const bool quickAttackTrigger();
	const bool avoid();
	const bool gaugeAttack1();
	const bool gaugeAttack2();
	const bool gaugeAttack3();
	const bool lockOn();
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