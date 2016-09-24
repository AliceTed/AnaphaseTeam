/**
* @file firstStep.h
* @brief 一段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class FirstStep:public IAirState
{
public:
	FirstStep();
	~FirstStep();
	/**
	* @fn
	* @brief 一段目のジャンプの力の設定
	*/
	void start(JumpControl* _control, Player* _player);
	/**
	* @fn
	* @brief 一段目のジャンプの異動処理
	*/
	void airAction(JumpControl* _control, Player* _player, float deltaTime);
private:
	void change(JumpControl* _control, Player* _player);
	AirAction_Ptr next(const Player* _player) const;
private:
	float m_JumpPower;
	static const float FirstStepPow;
};