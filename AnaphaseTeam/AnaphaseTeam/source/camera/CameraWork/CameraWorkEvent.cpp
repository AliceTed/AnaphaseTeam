#include "../../../header/camera/CameraWork/CameraWorkEvent.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/spline/SplineAnimManager.h"

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
	m_splineAnimManager->changeID(SPLINE_ANIMATION_ID::TEST);

	m_isEnd = false;
	m_nextCameraWork = E_CameraWorkID::NORMAL_BATTLE;
}

void CameraWorkEvent::run(float _deltaTime)
{
	GSvector3 position = m_camera->get_cameraTarget_player() + m_offset_target + GSvector3(0.0f, 0.5f, 0.0f);

	m_camera->tracking_lookAt(position);

	m_camera->tracking_position(m_splineAnimManager->run(1.0f / (60.0f * 30.0f), position));

	if (m_splineAnimManager->isEnd())
	{
		m_isEnd = true;
	}
}

E_CameraWorkID CameraWorkEvent::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkEvent::isEnd(void)
{
	return m_isEnd;
}
