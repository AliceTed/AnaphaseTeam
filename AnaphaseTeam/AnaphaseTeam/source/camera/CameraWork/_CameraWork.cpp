#include "../../../header/camera/CameraWork/_CameraWork.h"
#include "../../../header/camera/Camera.h"

CameraWork::CameraWork(Camera* _camera) : 
	m_camera(_camera)
{

}



CameraWork::~CameraWork()
{

}



void CameraWork::update(float _deltaTime)
{
	update_cameraWork(_deltaTime);
}



void CameraWork::draw(void)
{
	draw_cameraWork();

	return;
}



void CameraWork::update_cameraWork(float _deltaTime)
{
	m_deltaTime = _deltaTime;
}



void CameraWork::draw_cameraWork(void)
{
	m_camera->move(GSvector3(0.0f, 0.0f, 0.0f));

	m_camera->lookAt(GSvector3(0.0f, 0.0f, -1.0f));

	return;
}