#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "AnimationTimer.h"
#include "../data/id/ANIMATION_ID.h"
#include "../data/id/Model_ID.h"
/*
animation情報の管理

番号とタイマーと
loopかどうかなどの情報を持つ
*/

class Animation
{
public:
	/*
	enumなどでアニメーションの番号を管理してるとき用
	*/
	template<class T>
	Animation(MODEL_ID _code, T _animNo, AnimationTimer _timer, bool _isLoop = false)
		: m_isLoop(_isLoop), m_animNo(static_cast<unsigned int>(_animNo)), m_timer(_timer),
		m_anim_id(static_cast<unsigned int>(_code)), m_bone_id(static_cast<unsigned int>(_code))
	{}

	~Animation();
	void initialize();
	void update(float deltaTime);

	void stop();
	void start();
	const bool getIsEnd()const;
	unsigned int getAnimationNo();
	const float getSpeed() const;
	/*
	@fn 最大時間取得
	*/
	const float getEndTime()const;
	const float getCurrentTime()const;
	const bool getIsLoop() const;
private:
	void looping();

private:
	/*trueならループ*/
	bool m_isLoop;
	AnimationTimer m_timer;
	unsigned int m_animNo;
	unsigned int m_anim_id;
	unsigned int m_bone_id;
};

#endif