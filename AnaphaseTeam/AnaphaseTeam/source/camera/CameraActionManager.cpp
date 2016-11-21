#include "../../header/camera/CameraActionManager.h"
#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraActionDolly.h"
#include "../../header/camera/enum/stage1/CameraActionDollyStage1_1.h"
#include "../../header/camera/enum/stage1/CameraActionDollyStage1_2.h"
#include "../../header/camera/enum/stage1/CameraActionDollyStage1_3.h"
#include "../../header/camera/enum/CameraActionLockOn.h"
#include "../../header/camera/enum/CameraActionDead.h"


CameraActionManager::CameraActionManager(Camera* _camera) :
	m_camera(_camera),
	m_cameraActions(),
	m_elevation(40.0f),
	m_direction(0.0f)
{
	load();
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

	m_cameraActions.insert(cameraAction_map::value_type(0, std::make_shared<CameraActionLockOn>(camera)));
	m_cameraActions.insert(cameraAction_map::value_type(1, std::make_shared<CameraActionDead>(camera)));
}


int s_i = 0;
void CameraActionManager::run(void)
{
	const GSvector3& position = m_camera->cameraTarget_player();
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_RIGHT_SHOULDER))
	{
		s_i++;
	}

	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_LEFT_SHOULDER))
	{
		s_i--;
	}

	s_i = s_i < 0 ? 0 : s_i;
	s_i = s_i < 1 ? s_i : 1;

	m_cameraActions[s_i]->run();
}