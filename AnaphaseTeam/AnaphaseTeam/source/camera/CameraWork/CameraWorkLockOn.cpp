#include "../../../header/camera/CameraWork/CameraWorkLockOn.h"
#include "../../../header/camera/Camera.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/math/AMath.h"
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CameraWorkLockOn::CameraWorkLockOn(Camera* _camera, GSvector2* _rotate) :
	CameraWorkEmpty(_camera),
	m_parameter(std::make_unique<CWParameterReader>("./res/data/CameraWorkLockOn.cw")),
	m_rotate(_rotate),
	m_elevation(0.0f),
	m_distance(0.0f),
	m_distance_lockOn(0.0f),
	m_trackingSpeed(0.0, 0.0f),
	m_offset_value(0.0f),
	m_offset(0.0f)
{
	//読み込んだパラメータを各変数に代入
	m_elevation			= (*m_parameter)[0];
	m_distance			= (*m_parameter)[1];
	m_distance_lockOn	= (*m_parameter)[2];
	m_trackingSpeed		= GSvector2(
		(*m_parameter)[3],
		(*m_parameter)[4]
	);
	m_offset_value		= (*m_parameter)[5];
}



CameraWorkLockOn::~CameraWorkLockOn()
{

}

void CameraWorkLockOn::start(void)
{
	m_camera->initialize_zoom();

	m_nextCameraWork = "none";
	m_isEnd = false;
}

void CameraWorkLockOn::run(float _deltaTime)
{
	//長い変数をいちいち書くのがめんどくさいので
	const GSvector3& player = m_camera->get_cameraTarget_player();
	const GSvector3& target = m_camera->get_cameraTarget_enemy();

	//右が左か
	whichSide(player, target);

	//プレイヤーからターゲットまでのベクトルを求める
	GSvector3 vector = AMath::vec3_vector(player, target);

	//プレイヤーとターゲットの中点を求める
	GSvector3 center = AMath::vec3_center(player, target);

	//各距離
	float distance_p_e = vector.length();						//プレイヤーからエネミーまでの距離
	float distance_p_c = gsVector3Distance(&player, &center);	//プレイヤーから中点までの距離

																//カメラの位置をプレイヤーと中点の対角線上になるように更新
	update_toEleDir(vector, distance_p_c);

	//カメラワーク・ドリーの処理
	m_camera->cameraWork_dolly(
		(center + m_offset_target),
		*m_rotate,
		distance_p_c + m_distance,
		m_trackingSpeed
	);

	return;
}

std::string CameraWorkLockOn::nextCameraWork(void)
{
	return m_nextCameraWork;
}

bool CameraWorkLockOn::isEnd(void)
{
	return m_isEnd;
}


void CameraWorkLockOn::update_toEleDir(const GSvector3& _vec, float _distance)
{
	//プレイヤーエネミーの距離が一定値なったら、ロックオン処理をする
	if (_distance > m_distance_lockOn)
	{
		//プレイヤーからエネミーまでの仰角・方位角を求める
		gsVector3ToEleDir(&m_rotate->x, &m_rotate->y, &_vec);

		//求めた数値を調整する
		m_rotate->x = m_elevation;		//仰角は固定する
		m_rotate->y += 180 + m_offset;	//方位角は反転してオフセットを足す
	}
}

void CameraWorkLockOn::whichSide(const GSvector3 & _player, const GSvector3 & _target)
{
	//各点の設定
	const GSvector2 p1 = GSvector2(_player.x, _player.z);							//これが左右どっちかにあるかを調べる
	const GSvector2 p2 = GSvector2(m_camera->position().x, m_camera->position().z);	//カメラの位置
	const GSvector2 p3 = GSvector2(_target.x, _target.z);							//ターゲットの位置

	//左右どっちにあるかを調べる
	int n = AMath::side(p1, p2, p3);

	//n = 0なら右、n = 1なら右、n = 2なら左にずらす
	if (n >= 0)
	{
		m_offset = m_offset_value;
	}
	else
	{
		m_offset = -m_offset_value;
	}
}
