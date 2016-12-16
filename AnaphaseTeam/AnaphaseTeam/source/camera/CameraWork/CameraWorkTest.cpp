#include <vector>
#include <random>
#include "../../../header/camera/CameraWork/CameraWorkTest.h"
#include "../../../header/data/id/Model_ID.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/math/AMath.h"
#include "../../../header/animation/AnimationSpline.h"

CameraWorkTest::CameraWorkTest(Camera * _camera) :
	CameraWorkEmpty(_camera),
	max_num(10),
	points(max_num),
	vecs(std::make_shared<SplineVec3>()),
	animSpline(std::make_unique<AnimationSpline>(vecs.get()))
{

	std::random_device rnd;
	std::mt19937 mt(rnd());
	int i;

	for (i = 0; i < max_num - 1; i++)
	{
		std::uniform_real_distribution<> randX(-0.1f, 0.1f);
		std::uniform_real_distribution<> randY(1, 1.5f);

		points[i] = GSvector3(randX(mt), randY(mt), 0.0f);
	}
	points[i] = GSvector3(0.0f, 1.3f, 0.0f);

	vecs->init(points);
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
		animSpline->resetTime();
	}

	GSvector3 position = m_camera->get_cameraTarget_player();

	m_camera->tracking_lookAtOffset(animSpline->run(0.3f));
	m_camera->tracking_positionOffset(animSpline->run(0.3f));

	m_camera->tracking_lookAt(position, 1.0f);
	m_camera->tracking_position(position + GSvector3(0.0f, 1.3f, 5.0f), 1.0f);

	return;
}
