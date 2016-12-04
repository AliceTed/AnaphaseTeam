#include "../../header/myanimation/MyAnimation.h"
MyAnimation::MyAnimation()
	:m_container(),
	m_lerp(),
	m_current(0), 
	m_isEnd(false),
	m_mode(MYANIMATION_MODE::DEDAULT),
	m_target(nullptr)
{
}

MyAnimation::~MyAnimation()
{
	m_target = nullptr;
}

void MyAnimation::initialize()
{
	m_isEnd=false;
	m_current = 0;
	m_container.clear();
}

void MyAnimation::start(Transform* _target, MYANIMATION_MODE _mode)
{
	m_target = nullptr;
	m_target = _target;
	m_isEnd = false;
	m_current = _mode == MYANIMATION_MODE::DEDAULT? 0: size() -1;
	m_mode = _mode;
	next();
}

void MyAnimation::add(const TimeKeyFrame & _key)
{
	m_container.emplace_back(_key);
}

void MyAnimation::add(const Transform& _t, float _time)
{
	m_container.emplace_back(TimeKeyFrame(_t, _time));
}

void MyAnimation::update(float deltaTime)
{
	if (m_lerp.isEnd())
	{
		m_isEnd =!next();
		return;
	} 
	m_lerp.update(deltaTime);
}

const bool MyAnimation::isEnd() const
{
	return m_isEnd;
}

const unsigned int MyAnimation::size() const
{
	return m_container.size();
}

const bool MyAnimation::next()
{
	unsigned int prev = m_current;
	m_current+=static_cast<int>(m_mode);
	if (m_current >= size()||m_current<0)
	{
		m_current = prev;
		m_target = nullptr;
		return false;
	}

	Transform begin = m_container[prev].target;
	Transform next = m_container[m_current].target;
	unsigned int timeindex = m_mode == MYANIMATION_MODE::DEDAULT ? m_current : prev;
	float time = m_container[timeindex].time;
	m_lerp.start(m_target,begin, next, time);
	return true;
}
