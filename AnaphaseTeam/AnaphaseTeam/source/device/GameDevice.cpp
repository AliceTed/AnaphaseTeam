#include "../../header/device/GameDevice.h"


GameDevice::GameDevice()
	:m_input(),
	m_pattern(std::make_shared<InputPattern_A>(&m_input))
{
}

GameDevice::~GameDevice()
{
}

Input_Ptr & GameDevice::input()
{
	return m_pattern;
}
