#include "../../header/animation/AnimationSpline.h"
#include "../../header/math/SplineVec3.h"

AnimationSpline::AnimationSpline(void) :
	m_sVec3(std::make_unique<SplineVec3>()),
	m_timer(0.0f)
{

}

AnimationSpline::~AnimationSpline()
{

}

void AnimationSpline::init(const std::vector<GSvector3>& _points)
{
	m_sVec3->init(_points);
}

void AnimationSpline::resetTime(void)
{
	m_timer = 0;
}

GSvector3 AnimationSpline::run(float _speed, const GSvector3& _center)
{
	if (!m_sVec3->isEnd())
	{
		m_timer += _speed;
	}

	GSvector3 result =  m_sVec3->culc(m_timer) + _center;

	return result;
}
