#include <vector>
#include <random>
#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/spline/SplineAnimManager.h"

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

static float t = 0;
void CameraWorkTest::run(float _deltaTime)
{
	m_camera->tracking_lookAt(m_camera->get_cameraTarget_player());
	m_camera->tracking_position(m_camera->get_cameraTarget_player());

	return;
}
