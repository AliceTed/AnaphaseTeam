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
	return isJoyTriggerX() || isJoyTriggerY();
}

const bool Input::slowAttackTrigger() const
{
	return  isJoyTriggerY();
}

const bool Input::quickAttackTrigger() const
{
	return isJoyTriggerX();
}

const bool Input::avoidTrigger() const
{
	return isJoyTriggerB();
}




const bool Input::isJoyTriggerUp() const
{
	return gsGetJoyTrigger(0, GJOY_UP) == GS_TRUE;
}

const bool Input::isJoyTriggerDown() const
{
	return gsGetJoyTrigger(0, GJOY_DOWN) == GS_TRUE;
}

const bool Input::isJoyTriggerLeft() const
{
	return gsGetJoyTrigger(0, GJOY_LEFT) == GS_TRUE;
}

const bool Input::isJoyTriggerRight() const
{
	return gsGetJoyTrigger(0, GJOY_RIGHT) == GS_TRUE;
}

const bool Input::isJoyTriggerA() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_1) == GS_TRUE;
}

const bool Input::isJoyTriggerB() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_2) == GS_TRUE;
}



const bool Input::isJoyTriggerX() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_3) == GS_TRUE;
}

const bool Input::isJoyStateX() const
{
	return gsGetJoyState(0, GJOY_BUTTON_3) == GS_TRUE;
}

const bool Input::isJoyTriggerY() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_4) == GS_TRUE;
}

const bool Input::isJoyTriggerLB() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_5) == GS_TRUE;
}

const bool Input::isJoyTriggerRB() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_6) == GS_TRUE;
}

const bool Input::isJoyStateLB() const
{
	return gsGetJoyState(0, GJOY_BUTTON_5) == GS_TRUE;
}

const bool Input::isJoyStateRB() const
{
	return gsGetJoyState(0, GJOY_BUTTON_6) == GS_TRUE;
}

const bool Input::isJoyTriggerBACK() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_7) == GS_TRUE;
}

const bool Input::isJoyTriggerSTART() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_8) == GS_TRUE;
}

const bool Input::isJoyTriggerLeftThrust() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_9) == GS_TRUE;
}

const bool Input::isJoyTriggerRightThrust() const
{
	return gsGetJoyTrigger(0, GJOY_BUTTON_10) == GS_TRUE;
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
	int x, y;
	gsGetJoyRightAxis(0, &x, &y);
	return GSvector2(x, y);
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

const bool Input::isEscapeTrigger() const
{
	return gsGetKeyTrigger(GKEY_ESCAPE) == GS_TRUE;
}
