#include "..\..\../header\convenient\Timer.h"
#include "../../../header/math/Calculate.h"

const float Timer::FLAMETIME = 60.0f;
Timer::Timer(float _end)
	:m_Current(0.0f), m_End(_end*FLAMETIME)
{
}

Timer::~Timer()
{
}

void Timer::initialize()
{
	m_Current = 0.0f;
}

void Timer::update(float _speed)
{
	if (isEnd())return;

	Math::Clamp clamp;
	m_Current = clamp(m_Current + _speed, 0.0f, m_End);
}

const bool Timer::isEnd() const
{
	return m_Current >= m_End;
}

void Timer::setEndTime(float _end)
{
	m_End = _end*FLAMETIME;
}