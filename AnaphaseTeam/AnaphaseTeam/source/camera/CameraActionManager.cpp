#include "../../header/camera/CameraActionManager.h"
#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraActionDolly.h"
#include "../../header/camera/enum/CameraActionLockOn.h"
#include "../../header/camera/enum/CameraActionDead.h"
#include "../../header/camera/CameraActionData.h"
#include "../../header/camera/enum/CameraActionID.h"


CameraActionManager::CameraActionManager(Camera* _camera) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraActionData>()),
	m_current_cameraAction(CameraActionID::NONE)
{
	load();
}



CameraActionManager::~CameraActionManager()
{

}



void CameraActionManager::load(void)
{
	Camera* camera = m_camera;

	m_cameraData->load(
		CameraActionID::CAMERA_ACTION_LOCK_ON, 
		new CameraActionLockOn(camera)
	);
	m_cameraData->load(
		CameraActionID::CAMERA_ACTION_DEAD,
		new CameraActionDead(camera)
	);
}



void CameraActionManager::change_cameraWork(const CameraActionID& _id)
{
	m_current_cameraAction = _id;
}



void CameraActionManager::run(void)
{
	if (m_current_cameraAction == CameraActionID::NONE)
	{
		return;
	}

	m_cameraData->run(m_current_cameraAction);
}