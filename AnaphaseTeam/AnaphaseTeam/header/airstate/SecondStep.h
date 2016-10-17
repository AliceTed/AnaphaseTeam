/**
* @file secondStep.h
* @brief 二段ジャンプ目のステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class SecondStep:public IAirState
{
public:
	SecondStep(JumpControl* _control, Player* _player);
	~SecondStep();
	/**
	* @fn
	* @brief 二段目のジャンプの力の設定
	*/
	void start();
	/**
	* @brief ジャンプの移動処理
	*/
	void update(float deltaTime);
	const bool isEnd() const;
	std::shared_ptr<IAirState> next() const;
private:
	void change();
private:
	float m_JumpPower;
	static const float SecondStepPow;
	bool m_isEnd;
	AirAction_Ptr m_next;
	JumpControl* m_control;
	Player* m_player;
};