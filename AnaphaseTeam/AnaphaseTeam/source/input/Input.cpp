#include "../../header/device/Input.h"

Input::Input()
{
}
const GSvector2 Input::velocity()const
{
	return GSvector2(horizontal(),vertical());
}
//êÖïΩ	
const int Input::horizontal()const
{
	int f = gsGetKeyState(GKEY_D);
	f -= gsGetKeyState(GKEY_A);
	return f;
}
//êÇíº
const int Input::vertical()const
{
	int f = gsGetKeyState(GKEY_W);
	f -= gsGetKeyState(GKEY_S);
	return f;
}

const int Input::ymove() const
{
	int f = gsGetKeyState(GKEY_Z);
	f -= gsGetKeyState(GKEY_X);
	return f;
}

const bool Input::upTrigger()const
{
	return !!gsGetKeyTrigger(GKEY_UP);
}
const bool Input::downTrigger()const
{
	return !!gsGetKeyTrigger(GKEY_DOWN);
}
