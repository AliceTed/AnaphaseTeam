/**
* @file firstStep.h
* @brief 硬直落下ステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
class RestrictionFall :public IAirState
{
public:
	RestrictionFall();
	~RestrictionFall();
	/**
	* @fn
	* @brief ジャンプの力を０にする
	*/
	void start(JumpControl* _control, Player* _player);
	/**
	* @fn
	* @brief ジャンプ後の落下
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
private:
	void change(JumpControl* _control, Player* _player);
private:
	static const float Restriction;
};
