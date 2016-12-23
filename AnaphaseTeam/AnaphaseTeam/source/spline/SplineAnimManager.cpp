#include "../../header/spline/SplineAnimManager.h"
#include "../../header/spline/AnimationSplineData.h"
#include "../../header/spline/AnimationSpline.h"

SplineAnimManager::SplineAnimManager(void) :
	m_datas(std::make_unique<AnimationSplineData>()),
	m_currentID("test_position")
{

}

SplineAnimManager::~SplineAnimManager()
{

}

void SplineAnimManager::load(void)
{
	m_datas->add("test_position", "testPosition.sp");

	m_datas->add("test_lookAt", "testLookAt.sp");
}

void SplineAnimManager::changeID(std::string _id)
{
	m_currentID = _id;
	//m_datas->get(m_currentID)->resetTime();
}

AnimationSpline* SplineAnimManager::get(std::string _id)
{
	return m_datas->get(_id);
}

GSvector3 SplineAnimManager::run()
{
	return m_datas->get(m_currentID)->run();
}

bool SplineAnimManager::isEnd(void)
{
	return m_datas->get(m_currentID)->isEnd();
}
