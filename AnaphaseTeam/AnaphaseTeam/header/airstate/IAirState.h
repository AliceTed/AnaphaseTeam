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
public:
	virtual ~IAirState() {}
	virtual void start(JumpControl* _control, Player* _player) = 0;
	virtual void airAction(JumpControl* _control, Player* _player, float deltaTime) = 0;
};