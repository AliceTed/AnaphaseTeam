#include "../../header/device/InputPattern_A.h"
#include "../../header/device/Input.h"
InputPattern_A::InputPattern_A(Input * _input)
	:m_input(_input)
{
}

InputPattern_A::~InputPattern_A()
{
}

const GSvector2 InputPattern_A::velocity()
{
	return m_input->leftPadAxis();
}

const bool InputPattern_A::move()
{
	return velocity() != GSvector2(0, 0);
}

const bool InputPattern_A::walk()
{
	return false;
}

const bool InputPattern_A::jump()
{
	return m_input->isJoyTriggerA();
}

const bool InputPattern_A::attack()
{
	return slowAttackTrigger()||quickAttackTrigger();
}


const bool InputPattern_A::slowAttackTrigger()
{
	return  m_input->isJoyTriggerY();
}

const bool InputPattern_A::quickAttackTrigger()
{
	return m_input->isJoyTriggerX();
}

const bool InputPattern_A::avoid()
{
	return m_input->isJoyTriggerA();
}

const bool InputPattern_A::gaugeAttack1()
{
	return m_input->isJoyTriggerA() ;
}

const bool InputPattern_A::gaugeAttack2()
{
	return m_input->isJoyTriggerX();
}

const bool InputPattern_A::gaugeAttack3()
{
	return m_input->isJoyTriggerY() ;
}

const bool InputPattern_A::lockOn()
{
	return m_input->isJoyTriggerLeftThrust();
}

const bool InputPattern_A::specialSkillMode()
{
	return m_input->spState();
}

const bool InputPattern_A::up()
{
	return m_input->isJoyTriggerUp();
}

const bool InputPattern_A::down()
{
	return m_input->isJoyTriggerDown();
}

const bool InputPattern_A::right()
{
	return m_input->isJoyTriggerRight();
}

const bool InputPattern_A::left()
{
	return m_input->isJoyTriggerLeft();
}

const bool InputPattern_A::exit()
{
	return m_input->isJoyTriggerBACK()||m_input->isEscapeTrigger();
}

const bool InputPattern_A::reset()
{
	return m_input->isJoyTriggerSTART();
}

const bool InputPattern_A::decision()
{
	return m_input->isJoyTriggerB();
}
