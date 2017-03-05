#include "../../header/device/InputPattern_B.h"
#include "../../header/device/Input.h"
InputPattern_B::InputPattern_B(Input* _input)
	:m_input(_input)
{
}

InputPattern_B::~InputPattern_B()
{
}

const GSvector2 InputPattern_B::velocity()
{
	return m_input->leftPadAxis();
}

const bool InputPattern_B::move()
{
	return velocity() != GSvector2(0, 0);
}

const bool InputPattern_B::walk()
{
	return false;
}

const bool InputPattern_B::jump()
{
	return m_input->isJoyTriggerA();
}

const bool InputPattern_B::attack()
{
	return slowAttackTrigger() || quickAttackTrigger();
}


const bool InputPattern_B::slowAttackTrigger()
{
	return  m_input->isJoyTriggerB();
}

const bool InputPattern_B::quickAttackTrigger()
{
	return m_input->isJoyTriggerY();
}

const bool InputPattern_B::avoid()
{
	return m_input->isJoyRightTrigger();
}

const bool InputPattern_B::gaugeAttack1()
{
	return m_input->isJoyTriggerA();
}

const bool InputPattern_B::gaugeAttack2()
{
	return m_input->isJoyTriggerX();
}

const bool InputPattern_B::gaugeAttack3()
{
	return m_input->isJoyTriggerY();
}

const bool InputPattern_B::lockOn()
{
	return m_input->isJoyTriggerLeftThrust();
}

const bool InputPattern_B::specialSkillMode()
{
	return m_input->spState();
}

const bool InputPattern_B::up()
{
	return m_input->isJoyTriggerUp();
}

const bool InputPattern_B::down()
{
	return m_input->isJoyTriggerDown();
}

const bool InputPattern_B::right()
{
	return m_input->isJoyTriggerRight();
}

const bool InputPattern_B::left()
{
	return m_input->isJoyTriggerLeft();
}

const bool InputPattern_B::exit()
{
	return m_input->isJoyTriggerBACK() || m_input->isEscapeTrigger();
}

const bool InputPattern_B::reset()
{
	return m_input->isJoyTriggerSTART();
}

const bool InputPattern_B::decision()
{
	return m_input->isJoyTriggerA();
}
