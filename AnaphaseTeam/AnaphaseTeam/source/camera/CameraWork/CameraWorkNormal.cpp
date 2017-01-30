#include "camera/CameraWork/CameraWorkNormal.h"
#include "camera/Camera.h"
#include "camera/CameraWork/CWParameterReader.h"
#include "math/Calculate.h"
#include "math/AMath.h"
#include "camera/Perspective.h"
#include "camera/Zoom.h"
#include "convenient\Timer.h"

//コンストラクタ
CameraWorkNormal::CameraWorkNormal(Camera* _camera, GSvector2* _rotate) :
	CameraWorkEmpty(_camera),
	m_rotate(_rotate),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkNormal.cw")),
	m_speed_input(0.0f),
	m_distance(0.0f),
	m_trackingSpeed(0.0f, 0.0f),
	m_timer(std::make_unique<Timer>(5))
{
	init();
}

//デストラクタ
CameraWorkNormal::~CameraWorkNormal()
{
}

//初期化
void CameraWorkNormal::init()
{
	//読み込んだパラメータを各変数に代入
	m_speed_input = (*m_parameter)[0];
	m_distance = (*m_parameter)[1];
	m_trackingSpeed = { (*m_parameter)[2], (*m_parameter)[3] };
}

//開始
void CameraWorkNormal::start(void)
{
	Zoom* cameraZoom = m_camera->perspective()->zoom();
	cameraZoom->init(45.f);
	
	m_nextCameraWork = "none";
	m_isEnd = false;
}

//実行
void CameraWorkNormal::run(float _deltaTime)
{
	autoMove(_deltaTime);

	resetCamera();

	move();
}

//次のカメラワーク
std::string CameraWorkNormal::nextCameraWork(void)
{
	return m_nextCameraWork;
}

//終了したか？
bool CameraWorkNormal::isEnd(void)
{
	return m_isEnd;
}

//右スティックがしばらく倒されていなかったらカメラをプレイヤーの後ろに自動で移動させる処理
void CameraWorkNormal::autoMove(float _deltaTime)
{
	//右スティックが倒されていなかったら
	//タイマーを起動
	if (velocity().length() <= 0) {
		m_timer->update(_deltaTime);
	}
	//右スティックが倒されていたら
	//タイマーを初期化
	if (velocity().length() > 0) {
		m_timer->initialize();
	}
	//タイマーが終了していたら
	//プレイヤーの後ろにカメラを自動で動かす
	if (m_timer->isEnd())
	{
		float direction = m_camera->get_direction_player() + 180;
		AMath::lerp_angle(&m_rotate->y, direction, 0.01f);
	}
}

//右スティックが押し込まれたらカメラをプレイヤーの後ろに移動させる処理
void CameraWorkNormal::resetCamera(void)
{
	if (gsXBoxPadButtonTrigger(0, GS_XBOX_PAD_RIGHT_THUMB))
	{
		m_rotate->x = 20;
		m_rotate->y = AMath::normalizeAngle(m_camera->get_direction_player() + 180);
	}
}

//右スティックを倒した方向にカメラを移動させる処理
void CameraWorkNormal::move()
{
	const float CLAMP_ELEVATION = 70.f;
	const GSvector3& player = m_camera->get_cameraTarget_player();

	//回転軸を更新
	m_rotate->x -= velocity().y * m_speed_input;	//逆に動かしたいので引いとく
	m_rotate->y += velocity().x * m_speed_input;

	//ｘ軸の回転を制限
	m_rotate->x = Math::Calculate::clamp(m_rotate->x, -CLAMP_ELEVATION, CLAMP_ELEVATION);

	//カメラワーク・ドリーの処理
	m_camera->lookAt()->dolly(
		(player + m_offset_target),
		(*m_rotate),
		m_distance,
		m_trackingSpeed
	);
}

//右スティックの倒した数値を取得する
const GSvector2 CameraWorkNormal::velocity(void)
{
	GSvector2 velocity;
	gsXBoxPadGetRightAxis(0, &velocity);
	return velocity;
}
