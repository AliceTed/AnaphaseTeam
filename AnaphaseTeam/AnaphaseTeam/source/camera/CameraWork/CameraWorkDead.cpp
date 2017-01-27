#include "camera/CameraWork/CameraWorkDead.h"
#include "camera/Camera.h"
#include "camera/Zoom.h"

CameraWorkDead::CameraWorkDead(Camera* _camera) :
	CameraWorkEmpty(_camera),
	mTime(0.f)
{
}



CameraWorkDead::~CameraWorkDead()
{

}

void CameraWorkDead::start(void)
{
	m_isEnd = false;
	m_nextCameraWork = "normal_battle";
}

void CameraWorkDead::run(float _deltaTime)
{
	Zoom* cameraZoom = m_camera->zoom();
	const GSvector3& player = m_camera->get_cameraTarget_player();
	mTime += _deltaTime;

	m_camera->tracking_lookAt(player + m_offset_target, 0.5f);

	if (mTime > 320)
	{
		cameraZoom->zoomIN(0.1f);

		cameraZoom->clamp(10, 180);
	}

	return;
}

std::string CameraWorkDead::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkDead::isEnd(void)
{
	return m_isEnd;
}
