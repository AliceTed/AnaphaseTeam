#pragma once
#include <gslib.h>
#include "../convenient/Timer.h"
namespace Math
{
	template<class Vector>
	class TimeLerpVector
	{
	public:
		TimeLerpVector(const Vector& _current);
		~TimeLerpVector();
		void start(const Vector & _start, const Vector & _end, float _time);
		void update(float deltaTime);
		const bool isEnd()const;
		const Vector& current()const;
	private:
		Timer m_timer;

		Vector m_start;
		Vector m_end;
		Vector m_current;
		bool m_isStart;
	};
}
template<class Vector>
Math::TimeLerpVector<Vector>::TimeLerpVector(const Vector & _current)
	:m_start(),
	m_end(),
	m_current(_current),
	m_timer(1.0f),
	m_isStart(false)
{
}

template<class Vector>
Math::TimeLerpVector<Vector>::~TimeLerpVector()
{
}
template<class Vector>
void Math::TimeLerpVector<Vector>::start(const Vector & _start, const Vector & _end, float _time)
{
	m_start = _start;
	m_end = _end;
	m_current = _start;
	m_timer.setEndTime(_time);
	m_timer.initialize();
	m_isStart = true;
}

template<class Vector>
void Math::TimeLerpVector<Vector>::update(float deltaTime)
{
	if (!m_isStart)return;

	if (m_timer.isEnd())
	{
		m_isStart = false;
		m_current = m_end;
		return;
	}
	m_timer.update(deltaTime);
	Vector start = m_start;
	m_timer.accept([&](float _time, float _endtime){m_current = start.lerp(m_end, _time / _endtime);});
}
template<class Vector>
const bool Math::TimeLerpVector<Vector>::isEnd() const
{
	return m_timer.isEnd();
}

template<class Vector>
const Vector & Math::TimeLerpVector<Vector>::current() const
{
	return m_current;
}