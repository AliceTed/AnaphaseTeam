#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/Camera.h"

CameraWorkDead::CameraWorkDead(Camera* _camera) :
	CameraWork(_camera)
{
}



CameraWorkDead::~CameraWorkDead()
{

}

void CameraWorkDead::start(void)
{
	//カメラのズーム範囲を設定
	m_camera->zoom_clamp(20, 180);
}

//未完成
void CameraWorkDead::run(float _deltaTime)
{
	//変数の名前が長いので短い名前に変更
	const GSvector3& player = m_camera->cameraTarget_player();

	//注視点をプレイヤーに固定
	m_camera->tracking_lookAt(player + m_offset_target, 0.5f);

	//カメラをズームアップする
	m_camera->zoom_in(1.0f);

	return;
}