#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include <vector>
#include "../../../header/camera/Camera.h"
#include "../../../header/math/AMath.h"
#include "../../../header/math/Spline.h"

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

	Spline xs, ys, zs;

	std::vector<float> x = {  0,  10, 20,  30,  40 };
	std::vector<float> y = { 10,  20, 10,  20,  20 };
	std::vector<float> z = { 10,  10, 10,  10,  10 };
	xs.init(x, x.size() - 1);
	ys.init(y, y.size() - 1);
	zs.init(z, z.size() - 1);

	m_camera->tracking_lookAt(GSvector3(0.0f, 0.0f, 0.0f), 1.0f);
	m_camera->tracking_position(GSvector3(xs.culc(t), ys.culc(t), zs.culc(t)), 1.0f);

	return;
}
