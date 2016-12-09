#include "../../../header/camera/CameraWork/CameraWorkManager.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/camera/CameraWork/CameraWorkNormal.h"
#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/CameraWork/CameraWorkData.h"
#include "../../../header/camera/CameraWork/I_CameraWork.h"

CameraWorkManager::CameraWorkManager(Camera* _camera) :
	m_camera(_camera),
	m_cameraData(std::make_unique<CameraWorkData>()),
	m_rotate(0.0f, 0.0f),
	m_current_cameraWork(E_CameraWorkID::NONE)
{

}

CameraWorkManager::~CameraWorkManager()
{

}

void CameraWorkManager::load(void)
{
	//各カメラの追加
	m_cameraData->add(								//通常カメラ
		E_CameraWorkID::NORMAL,
		new CameraWorkNormal(m_camera, &m_rotate)
	);
	m_cameraData->add(								//ロックオンカメラ
		E_CameraWorkID::LOCK_ON,
		new CameraWorkLockOn(m_camera, &m_rotate)
	);
	m_cameraData->add(								//死亡カメラ
		E_CameraWorkID::DEAD,
		new CameraWorkDead(m_camera)
	);
}

void CameraWorkManager::change_cameraWork(const E_CameraWorkID _id)
{
	//現在のカメラワークの更新
	m_current_cameraWork = _id;
}

void CameraWorkManager::update(float _deltaTime)
{
	//カメラワークが何もないなら何もしない
	if (m_current_cameraWork == E_CameraWorkID::NONE)
	{
		return;
	}

	//現在のカメラワークの更新
	m_cameraData->get(m_current_cameraWork)->update(_deltaTime);

	return;
}

void CameraWorkManager::draw(void)
{
	//カメラワークが何もないなら何もしない
	if (m_current_cameraWork == E_CameraWorkID::NONE)
	{
		return;
	}

	//現在のカメラワークの描画
	m_cameraData->get(m_current_cameraWork)->draw();

	//カメラワークの更新
	m_camera->update();

	return;
}