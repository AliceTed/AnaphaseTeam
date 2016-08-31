/**
* @file IAirState.h
* @brief 空中時のアクションインターフェイス
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
class jumpControl;
class Player;
class IAirState
{
public:
	virtual ~IAirState() {}
	virtual void start(jumpControl* _jumpAction) = 0;
	virtual void airAction(jumpControl* _jumpAction, Player* _player, float deltaTime) = 0;
	virtual void next(jumpControl* _control) = 0;
};