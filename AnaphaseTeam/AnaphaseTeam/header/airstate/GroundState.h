/**
* @file groundState.h
* @brief 地上にいるときのステート
* @author 渋谷知樹
* @date 2016/08/29
*/
#pragma once
#include "IAirState.h"
#include "../convenient/Timer.h"
class GroundState:public IAirState
{
public:
	GroundState(JumpControl* _control, Player* _player);
	~GroundState();
	void start();
	void update(float deltaTime);
	const bool isEnd() const;
	std::shared_ptr<IAirState> next() const;
private:
	bool m_isEnd;
	JumpControl* m_control;
	Player* m_player;
	float m_timer;
	static const float ANIMSPEED;
};