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
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class JumpControl
{
public:
	JumpControl(Player* _player);
	~JumpControl();
	void initialize();
	void update(float deltaTime);
	const bool isEnd() const;

	void airActionChange(AirAction_Ptr _airAction);
	void end();
	void setPower(float _power);
	void jumping(float deltaTime, Player* _player);
private:
	Player* m_player;
	AirAction_Ptr m_airAction;
	bool m_isEnd;
	float m_JumpPower;
	static const float Acceleration;
	static const float MaxJumpPower;
};