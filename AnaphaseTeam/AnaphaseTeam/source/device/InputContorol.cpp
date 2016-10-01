#include "../../header/device/InputContorol.h"
#include "../../header/device/InputPattern_A.h"
#include "../../header/device/InputPattern_B.h"
InputContorol::InputContorol()
	:m_input(),
	m_pattern(std::make_shared<InputPattern_A>(&m_input))
{
}

InputContorol::~InputContorol()
{
}

void InputContorol::change(INPUT_PATTERN _pattern)
{
}

Input_Ptr InputContorol::getInput()
{
	return m_pattern;
}
