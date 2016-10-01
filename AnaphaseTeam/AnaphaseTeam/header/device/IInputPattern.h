#pragma once
#include <gslib.h>
class IInputPattern
{
public:
	virtual ~IInputPattern() {}
public://移動
	//水平,垂直
	virtual const GSvector2 velocity() = 0;
	virtual const bool move() = 0;
	virtual const bool walk() = 0;
public://アクション
	virtual const bool jump() = 0;
	virtual const bool attack() = 0;
	virtual const bool scythe() = 0;
	virtual const bool gun() = 0;
	virtual const bool avoid() = 0;
public:
	virtual const bool up() = 0;
	virtual const bool down() = 0;
	virtual const bool exit() = 0;
};