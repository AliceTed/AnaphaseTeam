#pragma once

#include "MYANIMATION_MODE.h"
#include "TimeKeyFrame.h"
#include "../math/TargetLerp.h"
#include "../math/TargetLerp.h"
#include <vector>
class MyAnimation
{
public:

	MyAnimation();
	~MyAnimation();
	void initialize();
	void start(Transform* _target, MYANIMATION_MODE _mode= MYANIMATION_MODE::DEDAULT);
	void add(const TimeKeyFrame& _key);
	void add(const Transform& _t, float _time);
	void update(float deltaTime);
	const bool isEnd()const;
	const unsigned int size()const;
private:
	//éüÇ…Ç¢ÇØÇ»Ç¢èÍçáfalse
	const bool next();
private:
	Transform* m_target;
	bool m_isEnd;
	std::vector<TimeKeyFrame> m_container;
	unsigned int m_current;
	MYANIMATION_MODE m_mode;
	Math::TargetLerp<Transform>m_lerp;
};