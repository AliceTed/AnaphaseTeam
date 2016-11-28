#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/ACalc.h"
#include "../../../header/math/Calculate.h"

CameraWorkLockOn::CameraWorkLockOn(Camera* _camera, GSvector2* _rotate) :
	CameraWork(_camera),
	m_rotate(_rotate)
{
}



CameraWorkLockOn::~CameraWorkLockOn()
{

}



void CameraWorkLockOn::update(void)
{
	m_camera->zoom(90.0f);

	GSvector2 rotate;
	float distance;
	GSvector3 vector;
	const GSvector3& player = m_camera->cameraTarget_player();
	const GSvector3& enemy = m_camera->cameraTarget_enemy();

	distance = gsVector3Distance(&player, &enemy);

	vector = enemy - player;

	gsVector3ToEleDir(&rotate.x, &rotate.y, &vector);

	rotate.x = 30;
	rotate.y += 180;

	m_camera->cameraWork_dolly(
		player,
		rotate,
		5,
		0.1f,
		0.5f
	);

	(*m_rotate) = rotate;

	m_camera->follow_target(enemy, 0.5f);

	return;
}