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

const int Input::rotate() const
{
	int f = gsGetKeyState(GKEY_E)|gsGetKeyState(GKEY_RIGHT);
	f -= gsGetKeyState(GKEY_Q)| gsGetKeyState(GKEY_LEFT);
	return f;
}

const bool Input::move() const
{
	return vertical() != 0 || horizontal() != 0;
}

const bool Input::walk() const
{
	return gsGetKeyState(GKEY_RSHIFT) == GS_TRUE;
}

const bool Input::jumpTrigger() const
{
	return gsGetKeyTrigger(GKEY_SPACE)==GS_TRUE;
}

const bool Input::chainTrigger() const
{
	return gsGetKeyTrigger(GKEY_LSHIFT) == GS_TRUE;
}

const bool Input::attckTrigger() const
{
	return gsGetKeyTrigger(GKEY_K) == GS_TRUE;
}


