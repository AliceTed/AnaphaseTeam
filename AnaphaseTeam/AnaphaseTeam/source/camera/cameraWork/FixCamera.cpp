#include "../../../header/camera/cameraWork/FixCamera.h"
#include "../../../header/camera/Camera.h"

FixCamera::FixCamera(Camera* _camera) :
	CameraWork(_camera)
{

}



FixCamera::~FixCamera()
{

}



void FixCamera::run(void)
{
	m_camera->follow_position(m_position, 0.5f);

	m_camera->lookAt(m_target);

	return;
}