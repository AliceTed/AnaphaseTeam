/**
@file CameraController
@brief カメラを操作する
@author Yuuho Aritomi*/
#include "../../header/camera\CameraController.h"
#include "../../header/camera/Camera.h"
#include "../../header/math/AMath.h"
#include "../../header/math/Calculate.h"
#include <string>

#include "../../header/camera/CameraWork/CameraWorkManager.h"

CameraController::CameraController(Camera* _camera) :
	m_cameraWorkManager(new CameraWorkManager(_camera)),
	m_deltaTime(0.0f)
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


void CameraController::draw(void)
{
	//カメラワーク・マネージャー実行
	m_cameraWorkManager->run(m_deltaTime);
}


void CameraController::change_cameraWork(const E_CameraWorkID _id)
{
	//カメラワークを指定ＩＤのものに変更
	m_cameraWorkManager->change_cameraWork(_id);
}