/**
* @file jumpControl.h
* @brief ÉWÉÉÉìÉvÇÃêßå‰
* @author èaíJímé˜
* @date 2016/08/29
*/
#pragma once
#include "../airstate/IAirState.h"
#include<gslib.h>
#include "../data/ANIMATION_ID.h"
class AnimatorOne;
typedef std::shared_ptr<IAirState> AirAction_Ptr;
class JumpControl
{
public:
	JumpControl(Player* _player);
	~JumpControl();
	void initialize();
	void update(float deltaTime);
	const bool isEnd() const;
	void changeMotion(AnimatorOne& _animator, ANIMATION_ID _id, float _animSpeed = 1.0f);
	void setPower(float _power);
	void jumping(float deltaTime, Player* _player);
private:
	void airActionChange();
	void change(AirAction_Ptr _next);
private:
	Player* m_player;
	AirAction_Ptr m_airAction;
	bool m_isEnd;
	float m_JumpPower;
	static const float Acceleration;
	static const float MaxJumpPower;
};