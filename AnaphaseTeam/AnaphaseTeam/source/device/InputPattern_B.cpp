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
	return GSvector2(0,0);
}

const bool InputPattern_B::move()
{
	return false;
}

const bool InputPattern_B::walk()
{
	return false;
}

const bool InputPattern_B::jump()
{
	return false;
}

const bool InputPattern_B::attack()
{
	return false;
}

const bool InputPattern_B::scythe()
{
	return false;
}

const bool InputPattern_B::gun()
{
	return false;
}

const bool InputPattern_B::avoid()
{
	return false;
}

const bool InputPattern_B::specialSkillMode()
{
	return false;
}

const bool InputPattern_B::up()
{
	return false;
}

const bool InputPattern_B::down()
{
	return false;
}

const bool InputPattern_B::right()
{
	return false;
}

const bool InputPattern_B::left()
{
	return false;
}

const bool InputPattern_B::exit()
{
	return false;
}

const bool InputPattern_B::reset()
{
	return false;
}

const bool InputPattern_B::decision()
{
	return m_input->isJoyTriggerB();
}
