#include "camera/CameraWork/CameraWorkManager.h"
#include "camera/Camera.h"
#include "camera/CameraWork/CameraWorkEmpty.h"
#include "camera/CameraWork/CameraWorkTest.h"
#include "camera/CameraWork/CameraWorkNormal.h"
#include "camera/CameraWork/CameraWorkLockOn.h"
#include "camera/CameraWork/CameraWorkDead.h"
#include "camera/CameraWork/CameraWorkData.h"
#include "camera/CameraWork/CameraWorkNormalBattle.h"
#include "camera/CameraWork/CameraWorkEvent.h"
#include "camera/CameraWork/I_CameraWork.h"
#include "spline/SplineAnimManager.h"

CameraWorkManager::CameraWorkManager(Camera* _camera, bool* _isLockOn) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraWorkData>()),
	m_splineAnimManager(std::make_shared<SplineAnimManager>()),
	m_rotate(0.0f, 0.0f),
	m_current_cameraWork("none"),
	m_isLockOn(_isLockOn)
{

}

CameraWorkManager::~CameraWorkManager()
{

}

void CameraWorkManager::load(void)
{
	//スプライン曲線アニメーション
	m_splineAnimManager->load();

	//各カメラの追加
	m_cameraData->add(								//何もしない
		"none",
		new CameraWorkEmpty(m_camera)
	);
	m_cameraData->add(								//テスト
		"test",
		new CameraWorkTest(m_camera)
	);
	m_cameraData->add(								//通常カメラ
		"normal",
		new CameraWorkNormal(m_camera, &m_rotate)
	);
	m_cameraData->add(								//ロックオンカメラ
		"lockon",
		new CameraWorkLockOn(m_camera, &m_rotate)
	);
	m_cameraData->add(
		"normal_battle",
		new CameraWorkNormalBattle(m_camera, m_isLockOn)
	);
	m_cameraData->add(								//死亡カメラ
		"dead",
		new CameraWorkDead(m_camera)
	);
	m_cameraData->add(
		"event",
		new CameraWorkEvent(m_camera, m_splineAnimManager.get())
	);
}

void CameraWorkManager::change_cameraWork(std::string _id)
{
	//現在のカメラワークの更新
	m_current_cameraWork = _id;

	//現在のカメラの初期化
	m_cameraData->get(m_current_cameraWork)->start();
}

void CameraWorkManager::run(float _deltaTime)
{
	if (m_cameraData->get(m_current_cameraWork)->isEnd())
	{
		change_cameraWork(m_cameraData->get(m_current_cameraWork)->nextCameraWork());
	}

	//現在のカメラワークの実行
	m_cameraData->get(m_current_cameraWork)->run(_deltaTime);

	return;
}