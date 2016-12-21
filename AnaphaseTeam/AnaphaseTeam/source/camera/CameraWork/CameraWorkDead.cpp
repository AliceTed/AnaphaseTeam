#include "../../../header/camera/CameraWork/CameraWorkDead.h"
#include "../../../header/camera/Camera.h"

CameraWorkDead::CameraWorkDead(Camera* _camera) :
	CameraWorkEmpty(_camera)
{
}



CameraWorkDead::~CameraWorkDead()
{

}

void CameraWorkDead::start(void)
{
	//カメラのズーム範囲を設定
	m_camera->zoom_clamp(10, 180);

	m_isEnd = false;
	m_nextCameraWork = "normal_battle";
}

static int i = 0;
void CameraWorkDead::run(float _deltaTime)
{
	//変数の名前が長いので短い名前に変更
	const GSvector3& player = m_camera->get_cameraTarget_player();
	i += _deltaTime;

	//注視点をプレイヤーに固定
	m_camera->tracking_lookAt(player + m_offset_target, 0.5f);

	if (i > 60)
	{
		//カメラをズームアップする
		m_camera->zoom_in(1.0f);
	}

	return;
}

std::string CameraWorkDead::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkDead::isEnd(void)
{
	return m_isEnd;
}
