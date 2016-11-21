/**
@file CameraController
@brief ƒJƒƒ‰‚ğ‘€ì‚·‚é
@author Yuuho Aritomi*/
#include "../../header/camera\CameraController.h"
#include "../../header/camera/Camera.h"
#include "../../header/camera/ACalc.h"
#include "../../header/math/Calculate.h"
#include <string>

#include "../../header/camera/CameraActionManager.h"
#include "../../header/camera/enum/CameraActionID.h"

CameraController::CameraController(Camera* _camera) :
	m_camera(_camera),
	m_distance(1),
	m_pitch(0),
	m_yow(0),
	m_cameraActionManager(new CameraActionManager(_camera))
{

}



CameraController::CameraController(
	Camera* _camera, 
	const float _distance,
	const float _pitch,
	const float _yow
) :
	m_camera(_camera),
	m_distance(_distance),
	m_pitch(_pitch),
	m_yow(_yow)
{
	ACalc::to_rad(&m_pitch);
	ACalc::to_rad(&m_yow);

	m_cameraActionManager->load();
}



void CameraController::update(void)
{
	m_camera->update();
}



void CameraController::change_control(Camera* _camera)
{
	m_camera = _camera;

	return;
}



void CameraController::run_cameraAction(const CameraActionID& _id)
{
	m_cameraActionManager->run(_id);
}
