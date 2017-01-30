#include "camera/CameraWork/CameraWorkNormal.h"
#include "camera/Camera.h"
#include "camera/CameraWork/CWParameterReader.h"
#include "math/Calculate.h"
#include "math/AMath.h"
#include "camera/Perspective.h"
#include "camera/Zoom.h"
#include "convenient\Timer.h"

CameraWorkNormal::CameraWorkNormal(Camera* _camera, GSvector2* _rotate) :
	CameraWorkEmpty(_camera),
	m_rotate(_rotate),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkNormal.cw")),
	m_speed_input(0.0f),
	m_distance(0.0f),
	m_trackingSpeed(0.0f, 0.0f),
	m_timer(std::make_unique<Timer>(5))
{
	//読み込んだパラメータを各変数に代入
	m_speed_input			= (*m_parameter)[0];
	m_distance				= (*m_parameter)[1];
	m_trackingSpeed = {
		(*m_parameter)[2],
		(*m_parameter)[3]
	};
}

CameraWorkNormal::~CameraWorkNormal()
{
}

void CameraWorkNormal::start(void)
{
	Zoom* cameraZoom = m_camera->perspective()->zoom();
	cameraZoom->init(45.f);
	
	m_nextCameraWork = "none";
	m_isEnd = false;
}

void CameraWorkNormal::run(float _deltaTime)
{
	const float CLAMP_ELEVATION = 70.f;

	//いちいちめんどくさいので宣言
	const GSvector3& player = m_camera->get_cameraTarget_player();

	//ボタンが押されたときカメラを後ろに回す処理
	resetCamera();

	/*if (velocity().length() <= 0)
		m_timer->update(_deltaTime);
	else {
		m_timer->initialize();
		m_trackingSpeed.x = (*m_parameter)[2];
	}

	if (m_timer->isEnd() == true) {
		float direction = m_camera->get_direction_player();
		m_rotate->y = direction + 180;
		m_trackingSpeed.x = 0.01f;
	}*/

	//回転軸を更新
	m_rotate->x -= velocity().y * m_speed_input;	//逆に動かしたいので引いとく
	m_rotate->y += velocity().x * m_speed_input;

	//ｘ軸の回転を制限
	m_rotate->x =Math::Calculate::clamp(m_rotate->x, -CLAMP_ELEVATION, CLAMP_ELEVATION);

	//カメラワーク・ドリーの処理
	m_camera->lookAt()->dolly(
		(player + m_offset_target),
		(*m_rotate),
		m_distance,
		m_trackingSpeed
	);

	return;
}

std::string CameraWorkNormal::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkNormal::isEnd(void)
{
	return m_isEnd;
}

const GSvector2 CameraWorkNormal::velocity(void)
{
	GSvector2 velocity;

	//inputはゲームデバイスから
	//右スティックの倒れた方向を取得する
	gsXBoxPadGetRightAxis(0, &velocity);

	return velocity;
}

void CameraWorkNormal::resetCamera(void)
{
	//右スティックが押し込まれたら
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_RIGHT_THUMB))
	{
		//カメラをプレイヤーの後ろに移動
		m_rotate->x = 20;
		m_rotate->y = AMath::normalizeAngle(m_camera->get_direction_player() + 180);
	}
}
