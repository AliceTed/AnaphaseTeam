#include "../../../header/camera/enum/CameraActionLockOn.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/ACalc.h"
#include "../../../header/math/Calculate.h"

CameraActionLockOn::CameraActionLockOn(Camera* _camera) :
	m_camera(_camera)
{
}



CameraActionLockOn::~CameraActionLockOn()
{

}



void CameraActionLockOn::run(void)
{
	m_camera->zoom_reset();

	Math::Clamp clamp;
	ACalc calc;
	float ele, dir, distance, pitch, yow;
	GSvector3 vector, target;
	const GSvector3& player = m_camera->cameraTarget_player();
	const GSvector3& enemy = m_camera->cameraTarget_enemy();

	m_camera->follow_target(enemy, 0.1f);

	distance = gsVector3Distance(&player, &enemy);

	ACalc::vector(&vector, player, enemy);

	gsVector3ToEleDir(&ele, &dir, &vector);

	pitch = 30;
	yow = dir + 180;

	ACalc::to_rad(&pitch);
	ACalc::to_rad(&yow);

	pitch = clamp(pitch, 0.0f, 360.0f);

	//‹——£§ŒÀ
	distance = clamp(distance, 5.0f, 100.0f);

	calc.rotate(&target, enemy, pitch, yow, distance* 1.6f);

	m_camera->follow_position(target, 0.7f);

	m_camera->update();

	return;
}