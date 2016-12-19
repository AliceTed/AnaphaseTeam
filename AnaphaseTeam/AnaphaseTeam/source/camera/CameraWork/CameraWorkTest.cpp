#include <vector>
#include <random>
#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/spline/SplineAnimManager.h"
#include "../../../header/spline/SPLINE_ANIMATION_ID.h"

CameraWorkTest::CameraWorkTest(Camera * _camera) :
	CameraWorkEmpty(_camera),
	shake(std::make_unique<SplineAnimManager>())
{
	shake->load();
	shake->changeID(SPLINE_ANIMATION_ID::TEST);
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
	m_camera->tracking_position(shake->run(0.01f));

	return;
}
