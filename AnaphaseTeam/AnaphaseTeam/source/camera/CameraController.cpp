/**
@file CameraController
@brief カメラを操作する
@author Yuuho Aritomi*/
#include "../../header/camera\CameraController.h"
#include <string>
#include "../../header/camera/Camera.h"
#include "../../header/math/AMath.h"
#include "../../header/math/Calculate.h"
#include "../../header/camera/CameraWork/CameraWorkManager.h"

/*
make_uniqueはunique_ptr作成用関数なので
正しくはmake_sharedをつかう
by 松尾
*/
CameraController::CameraController() :
	m_camera(std::make_shared<Camera>()),
	m_cameraWorkManager(std::make_shared<CameraWorkManager>(m_camera.get(), &m_isLockOn)),
	m_deltaTime(0.0f),
	m_isLockOn(false)
{
	//カメラワークの読み込み
	m_cameraWorkManager->load();
}

CameraController::~CameraController()
{
}


void CameraController::update(float _deltaTime)
{
	m_deltaTime = _deltaTime;
}


void CameraController::draw(IRenderer* _renderer)
{
	m_camera->run(_renderer);
	//カメラワーク・マネージャー実行
	m_cameraWorkManager->run(m_deltaTime);
}


void CameraController::collisionGround(const Map & _map)
{
	m_camera->collisionGround(_map);
}

void CameraController::change_cameraWork(const E_CameraWorkID _id)
{
	//カメラワークを指定ＩＤのものに変更
	m_cameraWorkManager->change_cameraWork(_id);
}

Camera * CameraController::get_camera(void)
{
	return m_camera.get();
}

void CameraController::set_isLockOn(bool _isLockOn)
{
	m_isLockOn = _isLockOn;

	return;
}
