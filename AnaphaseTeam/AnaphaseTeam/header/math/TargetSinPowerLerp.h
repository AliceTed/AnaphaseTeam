#pragma once
#include <gslib.h>
#include "../convenient/Timer.h"
#include "../math/Calculate.h"
namespace Math
{
	template<class Vector>
	class TargetSinPowerLerp
	{
	public:
		TargetSinPowerLerp(Vector _start);
		~TargetSinPowerLerp();
		void start(Vector *_target ,const Vector & _start, const Vector & _end, float _time);
		void update(float deltaTime);
		const bool isEnd()const;
		const Vector current()const;
	private:
		Timer m_timer;

		Vector m_start;
		Vector m_end;
		Vector *m_target;
		bool isStart;
	};
}
template<class Vector>
Math::TargetSinPowerLerp<Vector>::TargetSinPowerLerp(Vector _start)
	:m_start(_start),
	m_end(_start),
	m_target(nullptr),
	m_timer(1.0f),
	isStart(false)
{
}

template<class Vector>
Math::TargetSinPowerLerp<Vector>::~TargetSinPowerLerp()
{
}
template<class Vector>
void Math::TargetSinPowerLerp<Vector>::start(Vector* _target , const Vector & _start, const Vector & _end, float _time)
{
	m_start = _start;
	m_end = _end;
	m_target = _target;
	m_timer.setEndTime(_time);
	m_timer.initialize();
	isStart = true;
}

template<class Vector>
void Math::TargetSinPowerLerp<Vector>::update(float deltaTime)
{
	if (!isStart)return;

	if (m_timer.isEnd())
	{
		isStart = false;
		*m_target = m_end;
		m_target = nullptr;
		isStart = false;
		return;
	}

	m_timer.update(deltaTime);

	m_timer.accept([&](float _time, float _endtime) 
	{
		*m_target = GSvector2(Math::Calculate::sinPower(m_start, m_end, _time / _endtime, 0.5f).xy);
	});
}
template<class Vector>
const bool Math::TargetSinPowerLerp<Vector>::isEnd() const
{
	return m_timer.isEnd();
}

template<class Vector>
const Vector Math::TargetSinPowerLerp<Vector>::current() const
{
	if (m_target == nullptr)return m_end;
	return *m_target;
}