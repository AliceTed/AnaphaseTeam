#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include <list>
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
	GSvector3 vec;
	std::list<GSvector3> list;
	list.emplace_back(0.0f, 10.0f, 10.0f);
	list.emplace_back(30.0f, 50.0f, 10.0f);
	list.emplace_back(60.0f, 10.0f, 10.0f);
	list.emplace_back(90.0f, 200.0f, 10.0f);


	if (gsGetKeyState(GKEY_Z))
	{
		t += 0.01f;
	}
	if (gsGetKeyState(GKEY_X))
	{
		t -= 0.01f;
	}

	vec = AMath::bezierCurve(list, t);

	m_camera->tracking_lookAt(GSvector3(0.0f, 0.0f, 0.0f), 1.0f);
	m_camera->tracking_position(vec, 1.0f);

	return;
}
