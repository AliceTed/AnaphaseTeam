#include "../../../header/camera/CameraWork/_CameraWork.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CameraWork::CameraWork(Camera* _camera) : 
	m_camera(_camera),
	m_paramater_def(std::make_unique<CWParameterReader>("./res/data/CameraWorkDef.cw")),
	m_offset_target(0.0f, 0.0f, 0.0f)
{
	m_offset_target.x = m_paramater_def->get(0);
	m_offset_target.y = m_paramater_def->get(1);
	m_offset_target.z = m_paramater_def->get(2);
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