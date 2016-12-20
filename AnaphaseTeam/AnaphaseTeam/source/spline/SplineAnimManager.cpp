#include "../../header/spline/SplineAnimManager.h"
#include "../../header/spline/AnimationSplineData.h"
#include "../../header/spline/AnimationSpline.h"

SplineAnimManager::SplineAnimManager(void) :
	m_datas(std::make_unique<AnimationSplineData>()),
	m_currentID(SPLINE_ANIMATION_ID::TEST)
{

}

SplineAnimManager::~SplineAnimManager()
{
}

void SplineAnimManager::load(void)
{
	m_datas->add(SPLINE_ANIMATION_ID::TEST, "test.sp");
}

void SplineAnimManager::changeID(SPLINE_ANIMATION_ID _id)
{
	m_currentID = _id;
	m_datas->get(m_currentID)->resetTime();
}

GSvector3 SplineAnimManager::run(float _speed, const GSvector3 & _center)
{
	return m_datas->get(m_currentID)->run(_speed, _center);
}
