#include <vector>
#include <random>
#include "camera/CameraWork/CameraWorkTest.h"
#include "camera/Camera.h"
#include "spline/SplineAnimManager.h"

CameraWorkTest::CameraWorkTest(Camera * _camera) :
	CameraWorkEmpty(_camera),
	shake(std::make_unique<SplineAnimManager>())
{
}

CameraWorkTest::~CameraWorkTest()
{
}

void CameraWorkTest::start(void)
{
}

void CameraWorkTest::run(float _deltaTime)
{
	m_camera->lookAt()->lookAt(m_camera->get_cameraTarget_player());
	m_camera->lookAt()->move(m_camera->get_cameraTarget_enemy());
}
