#include "../../header/device/GameDevice.h"


GameDevice::GameDevice(Sound* _sound)
	:m_input(),
	m_sound(*_sound),
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

Sound & GameDevice::sound()
{
	return m_sound;
}
