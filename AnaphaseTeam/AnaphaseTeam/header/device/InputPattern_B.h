#pragma once
#include "IInputPattern.h"
class Input;
class InputPattern_B :public IInputPattern
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

	// IInputPattern を介して継承されました
	virtual const bool slowAttackTrigger() override;
	virtual const bool quickAttackTrigger() override;
	virtual const bool gaugeAttack1() override;
	virtual const bool gaugeAttack2() override;
	virtual const bool gaugeAttack3() override;
	virtual const bool lockOn() override;
};