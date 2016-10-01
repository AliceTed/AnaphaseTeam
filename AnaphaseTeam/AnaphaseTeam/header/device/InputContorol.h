#pragma once
#include "Input.h"
#include "IInputPattern.h"
#include <memory>
typedef std::shared_ptr<IInputPattern> Input_Ptr;
enum class INPUT_PATTERN:unsigned int
{
	A,
	B
};

class InputContorol
{
public:
	InputContorol();
	~InputContorol();
	void change(INPUT_PATTERN _pattern);
	Input_Ptr getInput();
private:
	Input m_input;
	Input_Ptr m_pattern;
};