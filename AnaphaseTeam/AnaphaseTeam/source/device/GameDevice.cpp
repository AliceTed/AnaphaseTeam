#include "../../header/device/GameDevice.h"
#include "../../header/device/InputPattern_A.h"
#include "../../header/device/InputPattern_B.h"

GameDevice::GameDevice()
	:m_pattern(std::make_shared<InputPattern_A>(&m_input))
{
}

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

void GameDevice::inputChange(IPUTTERN _pattern)
{
	switch (_pattern)
	{
	case IPUTTERN::INPUT_A:
		m_pattern = std::make_shared<InputPattern_A>(&m_input);
		break;
	case IPUTTERN::INPUT_B:
		m_pattern = std::make_shared<InputPattern_B>(&m_input);
		break;
	}
}
