#include <vector>
#include <random>
#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/animation//AnimationSpline.h"
#include "../../../header/data/AnimationSplineData.h"

CameraWorkTest::CameraWorkTest(Camera * _camera) :
	CameraWorkEmpty(_camera),
	shake(std::make_unique<AnimationSplineData>())
{
	std::vector<GSvector3> v =
	{
		{ 0.0f, 1.3f, 5.0f },
		{ 5.0f, 1.3f, 0.0f },
		{ 0.0f, 1.3f, -5.0f },
		{ -5.0f, 1.3f, 0.0f }
	};
	shake->Load(1, "test.sp");
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
	m_camera->tracking_position(shake->get(1)->run(0.01f, m_camera->get_cameraTarget_player()));

	return;
}
