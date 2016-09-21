/**
* @file firstStep.h
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"
class FirstStep:public IAirState
{
public:
	FirstStep();
	~FirstStep();
	/**
	* @fn
	* @brief 一段目のジャンプの力の設定
	*/
	void start(JumpControl* _control);
	/**
	* @fn
	* @brief 一段目のジャンプの異動処理
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
	/**
	* @fn
	* @brief 次のairStateをSecondStepにする
	*/
	void next(JumpControl* _control);
private:
	static const float FirstStepPow;
};