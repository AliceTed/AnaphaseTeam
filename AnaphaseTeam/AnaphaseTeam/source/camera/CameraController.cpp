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
	m_cameraWorkManager(new CameraWorkManager(_camera))
{
	//カメラワークの読み込み
	m_cameraWorkManager->load();
}


void CameraController::update(float _deltaTime)
{
	//カメラワーク・マネージャー更新処理
	m_cameraWorkManager->update(_deltaTime);
}


void CameraController::draw(void)
{
	//カメラワーク・マネージャー描画処理
	m_cameraWorkManager->draw();
}


void CameraController::change_cameraWork(const E_CameraWorkID _id)
{
	//カメラワークを指定ＩＤのものに変更
	m_cameraWorkManager->change_cameraWork(_id);
}