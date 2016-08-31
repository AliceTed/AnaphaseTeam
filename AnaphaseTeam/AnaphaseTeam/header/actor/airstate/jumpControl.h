/**
* @file jumpControl.h
* @brief ƒWƒƒƒ“ƒv‚Ì§Œä
* @author a’J’m÷
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include<gslib.h>
#include <memory>
class Player;
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class jumpControl
{
public:
	jumpControl();
	~jumpControl();
	const bool isGround()const;
	void update(Player* _player, float deltaTime);
	void groundHit();
	void jumping(Player* _player, float deltaTime);
	void start(const float _jumpStepPows);
	void airActionChange(AirAction_Ptr _airAction);
	void jump();

private:
	float m_JumpPower;
	float m_Acceleration;
	static const float MaxJumpPower;
	AirAction_Ptr m_airAction;
};