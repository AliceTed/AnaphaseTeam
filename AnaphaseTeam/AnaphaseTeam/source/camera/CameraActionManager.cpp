#include "../../header/camera/CameraActionManager.h"
#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraActionDolly.h"
#include "../../header/camera/enum/stage1/CameraActionDollyStage1_1.h"
#include "../../header/camera/enum/stage1/CameraActionDollyStage1_2.h"
#include "../../header/camera/enum/stage1/CameraActionDollyStage1_3.h"
#include "../../header/camera/enum/CameraActionLockOn.h"
#include "../../header/camera/enum/CameraActionDead.h"
#include "../../header/camera/cameraWork/FixCamera.h"
#include "../../header/camera/cameraWork/PanCamera.h"


CameraActionManager::CameraActionManager(Camera* _camera) :
	m_camera(_camera),
	m_cameraActions(),
	m_elevation(40.0f),
	m_direction(0.0f),
	m_cameraWork(new PanCamera(_camera))
{
	load();
	m_cameraWork->initialize(
		GSvector3(20, 5, -20),
		GSvector3(0, 0, 0));
}



CameraActionManager::~CameraActionManager()
{

}



void CameraActionManager::load(void)
{
	Camera* camera = m_camera;
	float* elevation = &m_elevation;
	float* direction = &m_direction;

	if (m_cameraActions.size() != 0)
	{
		m_cameraActions.clear();
	}
	m_cameraActions.insert(cameraAction_map::value_type(0, std::make_shared<CameraActionDollyStage1_1>(camera, new GSvector3(0.0f, 0.0f, 0.0f), elevation, direction)));
	m_cameraActions.insert(cameraAction_map::value_type(1, std::make_shared<CameraActionDollyStage1_2>(camera, new GSvector3(0.0f, 0.0f, 0.0f), elevation, direction)));
	m_cameraActions.insert(cameraAction_map::value_type(2, std::make_shared<CameraActionDollyStage1_3>(camera, new GSvector3(0.0f, 0.0f, 0.0f), elevation, direction)));
	m_cameraActions.insert(cameraAction_map::value_type(3, std::make_shared<CameraActionLockOn>(camera)));
	m_cameraActions.insert(cameraAction_map::value_type(4, std::make_shared<CameraActionDead>(camera)));
}

void CameraActionManager::run(void)
{
	m_cameraActions[3]->run();
}