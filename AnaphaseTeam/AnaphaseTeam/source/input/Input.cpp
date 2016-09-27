#include "../../header/device/Input.h"

Input::Input()
	:m_previousLeftTrigger(false),
	m_previousRightTrigger(false)
{
}
const GSvector2 Input::velocity()const
{
	return GSvector2(horizontal(),vertical());
}
//êÖïΩ	
const int Input::horizontal()const
{
	return leftPadAxis().x;
}
//êÇíº
const int Input::vertical()const
{
	return leftPadAxis().y;
}


const bool Input::move() const
{
	return vertical() != 0 || horizontal() != 0;
}

const bool Input::walk() const
{
	return gsGetKeyState(GKEY_RSHIFT) == GS_TRUE;
}

const bool Input::up() const
{
	return isJoyTriggerUp();
}

const bool Input::down() const
{
	return isJoyTriggerDown();
}

const bool Input::exit() const
{
	return gsGetKeyTrigger(GKEY_ESCAPE) == GS_TRUE|| isJoyTriggerBACK();
}

const bool Input::jumpTrigger() const
{
	return isJoyTriggerA();
}

const bool Input::attackTrigger() const
{
	return scytheTrigger() || gunTrigger();
}
const bool Input::scytheTrigger() const
{
	return isJoyTriggerX();
}

const bool Input::gunTrigger() const
{
	return gsGetKeyTrigger(GKEY_J) == GS_TRUE;
}

const bool Input::avoidTrigger() const
{
	return isJoyTriggerB();
}



const bool Input::isJoyTriggerUp() const
{
	return !!gsGetJoyTrigger(0, GJOY_UP);
}

const bool Input::isJoyTriggerDown() const
{
	return !!gsGetJoyTrigger(0, GJOY_DOWN);
}

const bool Input::isJoyTriggerLeft() const
{
	return !!gsGetJoyTrigger(0, GJOY_LEFT);
}

const bool Input::isJoyTriggerRight() const
{
	return !!gsGetJoyTrigger(0, GJOY_RIGHT);
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
	gsGetJoyTrigger(0, GJOY_DOWN);
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
	int x,y;
	gsGetJoyLeftAxis(0,&x,&y);
	//gsXBoxPadGetLeftAxis(0, &vector);
	return GSvector2(x,y);
}

const GSvector2 Input::rightPadAxis() const
{
	GSvector2 vector;
	gsXBoxPadGetRightAxis(0, &vector);
	return vector;
}

const bool Input::isJoyLeftTrigger()
{
	bool current = gsXBoxPadGetLeftTrigger(0) == 1.0f;
	bool result = current && !m_previousLeftTrigger;
	m_previousLeftTrigger = current;
	return result;
}

const bool Input::isJoyRightTrigger()
{
	bool current = gsXBoxPadGetRightTrigger(0) == 1.0f;
	bool result = current && !m_previousRightTrigger;
	m_previousRightTrigger = current;
	return result;
}