#include "../../header/device/GameDevice.h"

GameDevice & GameDevice::getInstacnce()
{
	static GameDevice self;
	return self;
}

Input_Ptr & GameDevice::input()
{
	return m_pattern;
}

Sound & GameDevice::sound()
{
	return m_sound;
}
