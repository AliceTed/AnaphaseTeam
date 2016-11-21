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



void CameraController::change_control(Camera* _camera)
{
	m_camera = _camera;

	return;
}



void CameraController::special_move1(
	GSvector3* _target1, 
	GSvector3* _target2, 
	float _elevation, 
	float _distance)
{
	m_cameraActionManager->run();
	return;
}



const float CameraController::direction(void) const
{
	ACalc calc;
	float ele, dir;
	GSvector3 vector;

	calc.vector(&vector, m_camera->position(), m_camera->target());

	gsVector3ToEleDir(&ele, &dir, &vector);

	return dir;
}
