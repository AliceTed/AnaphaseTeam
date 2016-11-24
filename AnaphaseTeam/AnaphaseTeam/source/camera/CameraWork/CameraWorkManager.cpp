#include "../../../header/camera/CameraWork/CameraWorkManager.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraActionDolly.h"
#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/CameraWork/CameraWorkData.h"
#include "../../../header/camera/CameraWork/CameraWorkID.h"


CameraWorkManager::CameraWorkManager(Camera* _camera) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraWorkData>()),
	m_current_cameraAction(CameraWorkID::NONE)
{
	load();
}



CameraWorkManager::~CameraWorkManager()
{

}



void CameraWorkManager::load(void)
{
	Camera* camera = m_camera;

	m_cameraData->load(
		CameraWorkID::CAMERA_ACTION_LOCK_ON,
		new CameraWorkLockOn(camera)
	);
	m_cameraData->load(
		CameraWorkID::CAMERA_ACTION_DEAD,
		new CameraWorkDead(camera)
	);
}



void CameraWorkManager::change_cameraWork(const CameraWorkID& _id)
{
	m_current_cameraAction = _id;
}



void CameraWorkManager::run(void)
{
	if (m_current_cameraAction == CameraWorkID::NONE)
	{
		return;
	}

	m_cameraData->run(m_current_cameraAction);
}