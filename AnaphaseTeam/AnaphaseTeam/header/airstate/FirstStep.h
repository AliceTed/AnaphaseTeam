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
	FirstStep(JumpControl* _control, Player* _player);
	~FirstStep();
	/**
	* @fn
	* @brief 一段目のジャンプの力の設定
	*/
	void start();
	/**
	* @fn
	* @brief 一段目のジャンプの異動処理
	*/
	void update(float deltaTime);
	const bool isEnd() const;
	std::shared_ptr<IAirState> next() const;
private:
	void change();
private:
	JumpControl * m_control;
	Player * m_player;
	float m_JumpPower;
	static const float FirstStepPow;
	bool m_isEnd;
	AirAction_Ptr m_next;
};