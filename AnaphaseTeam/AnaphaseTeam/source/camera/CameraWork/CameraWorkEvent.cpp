#include "../../../header/camera/CameraWork/CameraWorkEvent.h"
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

}

void CameraWorkEvent::run(float _deltaTime)
{
}