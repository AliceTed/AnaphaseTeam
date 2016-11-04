#pragma once

#include "IInputPattern.h"
class Input;
class InputPattern_A :public IInputPattern
{
public:
	InputPattern_A(Input* _input);
	~InputPattern_A();
public://�ړ�
	   //����,����
	const GSvector2 velocity();
	const bool move();
	const bool walk();
public://�A�N�V����
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