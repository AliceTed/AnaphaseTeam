#pragma once
#include "../device/Input.h" 
#include "../device/InputPattern_A.h"
#include <memory>
typedef std::shared_ptr<IInputPattern> Input_Ptr;
class GameDevice
{
public:
	GameDevice();
	~GameDevice();
	Input_Ptr& input();

private:
	//!input‹@”\
	Input m_input;
	//!input‚Ìpattern
	Input_Ptr m_pattern;

};
