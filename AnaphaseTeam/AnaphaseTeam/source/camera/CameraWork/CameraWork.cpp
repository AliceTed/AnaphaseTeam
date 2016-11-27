#include "../../../header/camera/CameraWork/CameraWork.h"
#include "../../../header/camera/Camera.h"

CameraWork::CameraWork(Camera* _camera) : 
	m_camera(_camera)
{

}



CameraWork::~CameraWork()
{

}



void CameraWork::run(void)
{
	update();

	return;
}



void CameraWork::update(void)
{
	m_camera->move(GSvector3(0.0f, 0.0f, 0.0f));

	m_camera->lookAt(GSvector3(0.0f, 0.0f, -1.0f));

	return;
}