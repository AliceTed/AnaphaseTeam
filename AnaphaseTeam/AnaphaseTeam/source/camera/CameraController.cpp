/**
@file CameraController
@brief �J�����𑀍삷��
@author Yuuho Aritomi*/
#include "../../header/camera\CameraController.h"
#include "../../header/camera/Camera.h"
#include "../../header/math/AMath.h"
#include "../../header/math/Calculate.h"
#include <string>

#include "../../header/camera/CameraWork/CameraWorkManager.h"

CameraController::CameraController() :
	m_camera(std::make_unique<Camera>()),
	m_cameraWorkManager(std::make_unique<CameraWorkManager>(m_camera.get())),
	m_deltaTime(0.0f)
{
	//�J�������[�N�̓ǂݍ���
	m_cameraWorkManager->load();
}

CameraController::~CameraController()
{
}


void CameraController::update(float _deltaTime)
{
	m_deltaTime = _deltaTime;
}


void CameraController::draw(void)
{
	//�J�������[�N�E�}�l�[�W���[���s
	m_cameraWorkManager->run(m_deltaTime);
}


void CameraController::collisionGround(const Map & _map)
{
	m_camera->collisionGround(_map);
}

void CameraController::change_cameraWork(const E_CameraWorkID _id)
{
	//�J�������[�N���w��h�c�̂��̂ɕύX
	m_cameraWorkManager->change_cameraWork(_id);
}

Camera * CameraController::get_camera(void)
{
	return m_camera.get();
}
