#include "../../../header/camera/CameraWork/CameraWorkNormal.h"
#include "../../../header/camera/Camera.h"

CameraWorkNormal::CameraWorkNormal(Camera* _camera, GSvector2* _rotate) :
	CameraWork(_camera),
	m_rotate(_rotate)
{

}



CameraWorkNormal::~CameraWorkNormal()
{

}



void CameraWorkNormal::update(void)
{
	const GSvector3& player = m_camera->cameraTarget_player();

	m_rotate->x -= velocity().y * 1.0f;
	m_rotate->y += velocity().x * 1.0f;

	m_camera->cameraWork_dolly(
		player,
		(*m_rotate),
		5,
		0.5f,
		0.5f
	);

	return;
}


const GSvector2 CameraWorkNormal::velocity(void)
{
	GSvector2 velocity;

	gsXBoxPadGetRightAxis(0, &velocity);

	return velocity;
}