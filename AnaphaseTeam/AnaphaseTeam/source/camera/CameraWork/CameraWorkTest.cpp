#include <vector>
#include <random>
#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include "../../../header/data/id/Model_ID.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/function/Shake.h"

CameraWorkTest::CameraWorkTest(Camera * _camera) :
	CameraWorkEmpty(_camera),
	shake(std::make_unique<Shake>(GSvector3(0.1f, 0.1f, 0.0f), 10))
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
	if (gsGetKeyTrigger(GKEY_Z))
	{
		shake->resetTime();
	}

	GSvector3 position = m_camera->get_cameraTarget_player();

	m_camera->tracking_lookAtOffset(shake->run(0.3f) + GSvector3(0.0f, 1.3f, 0.0f));
	m_camera->tracking_positionOffset(shake->run(0.3f) + GSvector3(0.0f, 1.3f, 0.0f));

	m_camera->tracking_lookAt(position, 1.0f);
	m_camera->tracking_position(position + GSvector3(0.0f, 1.3f, 5.0f), 1.0f);

	return;
}
