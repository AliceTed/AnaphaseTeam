#include "../../header/spline/AnimationSpline.h"
#include "../../header/spline/SplineVec3.h"

AnimationSpline::AnimationSpline(void) :
	m_sVec3(std::make_unique<SplineVec3>()),
	m_center(0.0f, 0.0f, 0.0f),
	m_timer(0.0f),
	m_speed(0.0f)
{

}

AnimationSpline::~AnimationSpline()
{

}

void AnimationSpline::init(const std::vector<GSvector3>& _points, float _speed, GSvector3 _center)
{
	m_sVec3->init(_points);
	m_speed = _speed;
	m_center = _center;
}

void AnimationSpline::resetTime(void)
{
	m_timer = 0;
}

GSvector3 AnimationSpline::run()
{
	if (!m_sVec3->isEnd())
	{
		m_timer += m_speed;
	}

	GSvector3 result =  m_sVec3->culc(m_timer) + m_center;

	return result;
}

bool AnimationSpline::isEnd(void)
{
	return m_sVec3->isEnd();
}
