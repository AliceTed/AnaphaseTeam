/**
* @file secondStep.h
* @brief 二段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "jumpControl.h"

class SecondStep:public IAirState
{
public:
	SecondStep();
	~SecondStep();
	/**
	* @fn
	* @brief 二段目のジャンプの力の設定
	*/
	void start(JumpControl* _control, Player* _player);
	/**
	* @brief ジャンプの移動処理
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
private:
	void change(JumpControl* _control, Player* _player);
	AirAction_Ptr next(const Player* _player) const;
private:
	float m_JumpPower;
	static const float SecondStepPow;
};