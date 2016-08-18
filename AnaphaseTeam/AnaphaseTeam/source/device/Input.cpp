#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

const bool Input::isJoyTriggerA() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_1);
}

const bool Input::isJoyTriggerB() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_2);
}

const bool Input::isJoyTriggerX() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_3);
}

const bool Input::isJoyTriggerY() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_4);
}

const bool Input::isJoyTriggerLB() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_5);
}

const bool Input::isJoyTriggerRB() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_6);
}

const bool Input::isJoyTriggerBACK() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_7);
}

const bool Input::isJoyTriggerSTART() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_8);
}

const bool Input::isJoyTriggerLeftThrust() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_9);
}

const bool Input::isJoyTriggerRightThrust() const
{
	return !!gsGetJoyTrigger(0, GJOY_BUTTON_10);
}

const GSvector2 Input::leftPadAxis() const
{
	GSvector2 vector;
	gsXBoxPadGetLeftAxis(0, &vector);
	return vector;
}

const GSvector2 Input::rightPadAxis() const
{
	GSvector2 vector;
	gsXBoxPadGetRightAxis(0, &vector);
	return vector;
}