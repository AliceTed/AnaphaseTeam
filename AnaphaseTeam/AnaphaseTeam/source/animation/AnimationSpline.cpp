#include "../../header/animation/AnimationSpline.h"
#include "../../header/math/SplineVec3.h"

AnimationSpline::AnimationSpline(SplineVec3* _sVec3):
	m_sVec3(_sVec3),
	m_timer(0.0f)
{

}

AnimationSpline::~AnimationSpline()
{

}

void AnimationSpline::resetTime(void)
{
	m_timer = 0;
}

GSvector3 AnimationSpline::run(float _speed)
{
	if (!m_sVec3->isEnd())
	{
		m_timer += _speed;
	}

	GSvector3 result =  m_sVec3->culc(m_timer);

	return result;
}
