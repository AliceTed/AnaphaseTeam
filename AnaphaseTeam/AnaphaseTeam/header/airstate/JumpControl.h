#pragma once
/**
* @file jumpControl.h
* @brief ジャンプの制御
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include<gslib.h>
#include <memory>
class Player;
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class JumpControl
{
public:
	JumpControl();
	~JumpControl();
	void update(Player* _player, float deltaTime);
	/**
	* @fn
	* @brief 着地
	*/
	void groundHit();
	/**
	* @fn
	* @brief ジャンプ力設定
	*/
	void jumping(Player* _player, float deltaTime);
	/**
	* @fn
	* @brief 各airStateから返ってきたジャンプ力を設定
	*/
	void start(const float _jumpStepPows);
	/**
	* @fn
	* @brief airStateを切り替える
	*/
	void airActionChange(AirAction_Ptr _airAction);
	/**
	* @fn
	* @brief ジャンプに関しての次のエアアクションステートの切り替え
	*/
	void jump();

private:
	float m_JumpPower;
	float m_Acceleration;
	static const float MaxJumpPower;
	AirAction_Ptr m_airAction;
};