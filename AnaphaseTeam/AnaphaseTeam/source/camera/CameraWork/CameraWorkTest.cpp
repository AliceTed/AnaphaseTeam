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
	ASplineVec3 vecs;

	GSvector3 position = m_camera->cameraTarget_player();

	std::vector<GSvector3> vec =
	{
		GSvector3(0, 7, -7),
		GSvector3(-6, 6, 0),
		GSvector3(0, 5, 5),
		GSvector3(4, 4, 0),
		GSvector3(0, 3, -3),
		GSvector3(-2, 2, 0),
		GSvector3(0, 1.3f, 1.3f)
	};

	vecs.init(vec);

	m_camera->tracking_lookAt(m_camera->cameraTarget_player() + GSvector3(0, 1.3f, 0), 1.0f);
	m_camera->tracking_position(position + vecs.culc(t), 1.0f);

	return;
}
