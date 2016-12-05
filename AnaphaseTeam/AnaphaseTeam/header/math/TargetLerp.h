#pragma once
#pragma once
#include <gslib.h>
#include "../convenient/Timer.h"
namespace Math
{
	template<class Vector>
	class TargetLerp
	{
	public:
		TargetLerp();
		~TargetLerp();
		void start(Vector* _target,const Vector & _start, const Vector & _end, float _time);
		void update(float deltaTime);
		const bool isEnd()const;
	private:
		Timer m_timer;

		Vector m_start;
		Vector m_end;
		Vector* m_target;
		bool isStart;
	};
}
template<class Vector>
Math::TargetLerp<Vector>::TargetLerp()
	:m_start(),
	m_end(),
	m_target(nullptr),
	m_timer(1.0f),
	isStart(false)
{
}

template<class Vector>
Math::TargetLerp<Vector>::~TargetLerp()
{
	m_target = nullptr;
}
template<class Vector>
void Math::TargetLerp<Vector>::start(Vector* _target, const Vector & _start, const Vector & _end, float _time)
{
	m_target = _target;
	m_start = _start;
	m_end = _end;
	*m_target = _start;
	m_timer.setEndTime(_time);
	m_timer.initialize();
	isStart = true;
}

template<class Vector>
void Math::TargetLerp<Vector>::update(float deltaTime)
{
	if (!isStart)return;

	if (m_timer.isEnd())
	{
		isStart = false;
		*m_target = m_end;
		m_target = nullptr;
		return;
	}
	m_timer.update(deltaTime);
	Vector start = m_start;
	m_timer.accept([&](float _time, float _endtime) {*m_target = start.lerp(m_end, _time / _endtime); });
}
template<class Vector>
const bool Math::TargetLerp<Vector>::isEnd() const
{
	return m_timer.isEnd();
}