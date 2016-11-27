#include "../../../header/camera/CameraWork/CameraWorkManager.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraActionDolly.h"
#include "../../../header/camera/CameraWork/CameraWorkNormal.h"
#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/CameraWork/CameraWorkData.h"
#include "../../../header/camera/CameraWork/I_CameraWork.h"


CameraWorkManager::CameraWorkManager(Camera* _camera) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraWorkData>()),
	m_rotate(0.0f, 0.0f),
	m_current_cameraAction(E_CameraWorkID::NONE)
{
	load();
}



CameraWorkManager::~CameraWorkManager()
{

}



void CameraWorkManager::load(void)
{
	m_cameraData->add(
		E_CameraWorkID::NORMAL,
		new CameraWorkNormal(m_camera, &m_rotate)
	);
	m_cameraData->add(
		E_CameraWorkID::LOCK_ON,
		new CameraWorkLockOn(m_camera, &m_rotate)
	);
	m_cameraData->add(
		E_CameraWorkID::DEAD,
		new CameraWorkDead(m_camera)
	);
}



void CameraWorkManager::change_cameraWork(const E_CameraWorkID _id)
{
	m_current_cameraAction = _id;
}



void CameraWorkManager::run(void)
{
	if (m_current_cameraAction == E_CameraWorkID::NONE)
	{
		return;
	}

	m_cameraData->get(m_current_cameraAction)->run();
}