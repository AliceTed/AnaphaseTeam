/**
* @file IAirState.h
* @brief 空中時のアクションインターフェイス
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include <memory>
class JumpControl;
class Player;
class IAirState
{
//public:
//	typedef std::shared_ptr<IAirState> AirAction_Ptr;
public:
	virtual ~IAirState() {}
	virtual void start() = 0;
	virtual void update(float deltaTime) = 0;
	virtual const bool isEnd() const = 0 ;
	virtual std::shared_ptr<IAirState> next() const = 0;

};