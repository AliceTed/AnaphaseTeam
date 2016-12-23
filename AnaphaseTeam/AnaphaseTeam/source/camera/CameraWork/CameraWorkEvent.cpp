#include "../../../header/camera/CameraWork/CameraWorkEvent.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/spline/SplineAnimManager.h"
#include "../../../header/spline/AnimationSpline.h"

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
	m_camera->tracking_lookAt(m_splineAnimManager->get("test_lookAt")->run(1.0f / (60.0f * 30.0f)));

	m_camera->tracking_position(m_splineAnimManager->get("test_position")->run(1.0f / (60.0f * 30.0f)));

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
