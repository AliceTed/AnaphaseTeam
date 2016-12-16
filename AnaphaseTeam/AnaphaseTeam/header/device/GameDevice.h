#pragma once
#include "../device/Input.h" 
#include "../device/IInputPattern.h"
#include "../sound/Sound.h"
#include <memory>
enum class IPUTTERN
{
	INPUT_A,
	INPUT_B
};

typedef std::shared_ptr<IInputPattern> Input_Ptr;
class GameDevice
{
public:
	static GameDevice& getInstacnce();

	Input_Ptr& input();
	Sound & sound();
	void inputChange(IPUTTERN _pattern);
private:
	GameDevice();
	GameDevice(const GameDevice& other);
	GameDevice& operator = (const GameDevice& other);

	//!input‹@”\
	Input m_input;
	//!input‚Ìpattern
	Input_Ptr m_pattern;
	Sound m_sound;
};
