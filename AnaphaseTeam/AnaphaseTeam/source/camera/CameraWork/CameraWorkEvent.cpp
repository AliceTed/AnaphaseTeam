#include <sstream> //å„Ç≈è¡Ç∑
#include <string>  //å„Ç≈è¡Ç∑
#include "camera/CameraWork/CameraWorkEvent.h"
#include "camera/Camera.h"
#include "spline/SplineAnimManager.h"
#include "spline/AnimationSpline.h"

CameraWorkEvent::CameraWorkEvent(Camera * _camera, SplineAnimManager * _splineAnimManager) :
	CameraWorkEmpty(_camera),
	m_splineAnimManager(_splineAnimManager)
{
}

CameraWorkEvent::~CameraWorkEvent()
{

}

void CameraWorkEvent::start(void)
{
	//m_splineAnimManager->changeID("test_position");
	m_splineAnimManager->get("test_position")->resetTime();
	m_splineAnimManager->get("test_lookAt")->resetTime();

	m_isEnd = false;
	m_nextCameraWork = "normal_battle";
}

void CameraWorkEvent::run(float _deltaTime)
{
	m_camera->lookAt(m_splineAnimManager->get("test_lookAt")->run());

	m_camera->move(m_splineAnimManager->get("test_position")->run());

	if (m_splineAnimManager->isEnd())
	{
		m_isEnd = true;
	}
}

std::string CameraWorkEvent::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkEvent::isEnd(void)
{
	return m_isEnd;
}
