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
	int f = gsGetKeyState(GKEY_RIGHT);
	f -= gsGetKeyState(GKEY_LEFT);
	return f;
}
//êÇíº
const int Input::vertical()const
{
	int f = gsGetKeyState(GKEY_UP);
	f -= gsGetKeyState(GKEY_DOWN);
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
