#pragma once
#include <gslib.h>
class IInputPattern
{
public:
	virtual ~IInputPattern() {}
public://ˆÚ“®
	//…•½,‚’¼
	virtual const GSvector2 velocity() = 0;
	virtual const bool move() = 0;
	virtual const bool walk() = 0;
public://ƒAƒNƒVƒ‡ƒ“
	virtual const bool jump() = 0;
	virtual const bool attack() = 0;
	virtual const bool scythe() = 0;
	virtual const bool charge() = 0;
	virtual const bool gun() = 0;
	virtual const bool avoid() = 0;
	virtual const bool chargeAttack1() = 0;
	virtual const bool chargeAttack2() = 0;
	virtual const bool chargeAttack3() = 0;
public:
	virtual const bool up() = 0;
	virtual const bool down() = 0;
	virtual const bool right() = 0;
	virtual const bool left() = 0;
	virtual const bool exit() = 0;
public://debug
	virtual const bool reset() = 0;
};