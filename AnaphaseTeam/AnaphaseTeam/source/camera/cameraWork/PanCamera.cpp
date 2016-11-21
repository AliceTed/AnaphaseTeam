#include "../../../header/camera/cameraWork/PanCamera.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/ACalc.h"

PanCamera::PanCamera(Camera* _camera) :
	CameraWork(_camera)
{

}



PanCamera::~PanCamera()
{

}


void PanCamera::run(void)
{
	m_camera->follow_position(m_position, 0.5f);

	m_camera->lookAt_pan(m_target, 0);
}