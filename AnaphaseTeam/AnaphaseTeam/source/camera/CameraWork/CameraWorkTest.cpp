#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include <vector>
#include "../../../header/data/id/Model_ID.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/math/AMath.h"

CameraWorkTest::CameraWorkTest(Camera * _camera) :
	CameraWorkEmpty(_camera)
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
	if (gsGetKeyState(GKEY_Z))
	{
		t += 0.01f;
	}
	if (gsGetKeyState(GKEY_X))
	{
		t -= 0.01f;
	}
	ASpline xs, ys, zs;

	GSvector3 position = m_camera->cameraTarget_player();

	std::vector<float> x = { position.x    , position.x - 6, position.x    , position.x + 4, position.x       , position.x - 2   , position.x };
	std::vector<float> y = { position.y + 7, position.y + 6, position.y + 5, position.y + 4, position.y + 3   , position.y + 2, position.y + 1.3f };
	std::vector<float> z = { position.z - 7, position.z    , position.z + 5, position.z    , position.z - 3   , position.z       , position.z + 1.3f };
	xs.init(x);
	ys.init(y);
	zs.init(z);

	m_camera->tracking_lookAt(m_camera->cameraTarget_player() + GSvector3(0, 1.3f, 0), 1.0f);
	m_camera->tracking_position(GSvector3(xs.culc(t), ys.culc(t), zs.culc(t)), 1.0f);

	return;
}
