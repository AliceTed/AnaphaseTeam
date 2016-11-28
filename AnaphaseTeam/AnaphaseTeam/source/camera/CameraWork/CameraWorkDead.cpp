#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/Camera.h"

CameraWorkDead::CameraWorkDead(Camera* _camera) :
	CameraWork(_camera)
{
	m_camera->zoom_clamp(20, 180);
}



CameraWorkDead::~CameraWorkDead()
{

}


//������
void CameraWorkDead::update(void)
{
	const GSvector3& player = m_camera->cameraTarget_player();

	m_camera->follow_target(player + GSvector3(0, 1, 0), 0.5f);

	m_camera->zoom_in(1.0f);

	m_camera->update();

	return;
}