#pragma once
#include "../device/Input.h" 
#include "../device/InputPattern_A.h"
#include "../sound/Sound.h"
#include <memory>
typedef std::shared_ptr<IInputPattern> Input_Ptr;
class GameDevice
{
public:
	static GameDevice& getInstacnce();

	Input_Ptr& input();
	Sound & sound();

private:
	GameDevice() :
		m_pattern(std::make_shared<InputPattern_A>(&m_input))
	{}
	GameDevice(const GameDevice& other);
	GameDevice& operator = (const GameDevice& other);

	//!input‹@”\
	Input m_input;
	//!input‚Ìpattern
	Input_Ptr m_pattern;
	Sound m_sound;
};
