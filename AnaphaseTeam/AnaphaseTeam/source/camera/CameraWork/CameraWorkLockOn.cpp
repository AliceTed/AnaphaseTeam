#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/ACalc.h"
#include "../../../header/math/Calculate.h"

CameraWorkLockOn::CameraWorkLockOn(Camera* _camera) :
	CameraWork(_camera)
{
}



CameraWorkLockOn::~CameraWorkLockOn()
{

}



void CameraWorkLockOn::update(void)
{
	m_camera->zoom(90.0f);

	float elevation, direction, distance;
	GSvector3 vector;
	const GSvector3& player = m_camera->cameraTarget_player();
	const GSvector3& enemy = m_camera->cameraTarget_enemy();

	distance = gsVector3Distance(&player, &enemy);

	vector = enemy - player;

	gsVector3ToEleDir(&elevation, &direction, &vector);

	m_camera->cameraWork_dolly(
		player,
		10,
		direction + 180,
		5,
		0.1f,
		0.5f
	);

	m_camera->follow_target(enemy, 0.5f);

	return;
}