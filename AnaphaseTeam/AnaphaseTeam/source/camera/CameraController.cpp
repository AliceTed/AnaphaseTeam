/**
@file CameraController
@brief カメラを操作する
@author Yuuho Aritomi*/
#include "../../header/camera\CameraController.h"
#include "../../header/camera/Camera.h"
#include "../../header/camera/ACalc.h"
#include "../../header/math/Calculate.h"
#include <string>

#include "../../header/camera/CameraWork/CameraWorkManager.h"

CameraController::CameraController(Camera* _camera) :
	m_camera(_camera),
	m_distance(1),
	m_pitch(0),
	m_yow(0),
	m_cameraWorkManager(new CameraWorkManager(_camera))
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

	m_cameraWorkManager->load();
}


void CameraController::update(float _deltaTime)
{
	m_cameraWorkManager->update(_deltaTime);
}


void CameraController::draw(void)
{
	m_cameraWorkManager->draw();

	m_camera->update();
}


void CameraController::change_cameraWork(const E_CameraWorkID _id)
{
	m_cameraWorkManager->change_cameraWork(_id);
}