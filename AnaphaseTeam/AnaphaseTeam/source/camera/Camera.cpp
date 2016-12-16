#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraTarget.h"
#include "../../header/math/Calculate.h"
#include "../../header/math/AMath.h"
#include "../../header/data/id/OCTREE_ID.h"
#include "../../header/map/Map.h"
#include "../../header/camera/SLookAt.h"
#include <random>

const GSvector3 Camera::RAY_DONW = GSvector3(0, -1, 0);		//レイは下に飛ばしたいのでｙ成分に-1する

const float Camera::DEF_FOV				= 45.0f;			//視野角のデフォルト値は45度で固定
const GSvector2 Camera::DEF_FOV_CLAMP	= { 2.0f, 180.0f };	//視野角の範囲は2.0~180.0の範囲

Camera::Camera() :
	m_perspective(GSvector4(DEF_FOV, 1280.0f / 720.0f, 0.3f, 1000.0f)),
	m_fov_clamp(DEF_FOV_CLAMP.x, DEF_FOV_CLAMP.y),
	m_lookAt(std::make_unique<SLookAt>(GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 1.0f, 0.0f))),
	m_rotate_dolly(0.0f, 0.0f),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>()),
	m_direction_player(0.0f)
{
	//投影変換行列の初期化
	gsMatrix4Identity(&m_mat_projection);
}

Camera::~Camera()
{
}

void Camera::initialize_zoom(void)
{
	//視野角を初期化
	m_perspective.x	= DEF_FOV;
	//視野角の指定範囲を初期化
	m_fov_clamp.x		= DEF_FOV_CLAMP.x;
	m_fov_clamp.y		= DEF_FOV_CLAMP.y;
}

void Camera::reset_offset(void)
{
	m_lookAt->position_offset = { 0.0f, 0.0f, 0.0f };
	m_lookAt->target_offset = { 0.0f, 0.0f, 0.0f };
}

void Camera::update(void)
{
	//視野角・遠近情報を更新
	update_perspective();

	//カメラ位置情報を更新
	update_lookAt();

	return;
}

void Camera::cameraWork_tilt_pan(
	const GSvector3&	_position_camera,
	const GSvector2&	_rotate,
	const GSvector2&	_trackingSpeed
)
{
	//追尾処理更新
	update_tracking(
		_position_camera,
		AMath::rotate_sphericalCoordinates(m_lookAt->position, _rotate, 10),	//球面座標を利用した回転
		_trackingSpeed
	);

	return;
}

void Camera::cameraWork_dolly(
	const GSvector3&	_position_target,
	const GSvector2&	_rotate,
	const float			_distance,
	const GSvector2&	_trackingSpeed
)
{
	//仰角と方位角のラープ
	AMath::lerp_eleDir(
		&m_rotate_dolly,
		_rotate,
		_trackingSpeed.x
	);

	//球面座標を使った回転
	GSvector3 position = AMath::rotate_sphericalCoordinates(
		_position_target,
		AMath::to_rad(m_rotate_dolly),
		_distance
	);

	//追尾処理更新
	update_tracking(
		position,
		_position_target,
		_trackingSpeed
	);

	return;
}

void Camera::set_cameraTarget_player(const GSvector3& _target)
{
	//プレイヤーの位置を保持
	m_cameraTarget_player->lookAt(_target);

	return;
}

void Camera::set_cameraTarget_enemy(const GSvector3& _target)
{
	//エネミーの位置を保持
	m_cameraTarget_enemy->lookAt(_target);

	return;
}

void Camera::set_direction_player(float _direction)
{
	//プレイヤーの方位角を保持
	m_direction_player = _direction;
}

void Camera::tracking_position(const GSvector3& _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* position = &m_lookAt->position;

	//３次元ベクトルの線形補間
	gsVector3Lerp(position, position, &_target, _speed);

	return;
}

void Camera::tracking_lookAt(const GSvector3& _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* target = &m_lookAt->target;

	//３次元ベクトルの線形補間
	gsVector3Lerp(target, target, &_target, _speed);

	return;
}

void Camera::collisionGround(const Map & _map)
{
	//これにレイのヒットした位置が保持される
	GSvector3 intersectPos;

	//カメラが地面に当たっていたら
	//カメラの位置を修正
	if (isHitGround(_map, &intersectPos, &m_lookAt->position))
	{
		m_lookAt->position.y = intersectPos.y;
	}
}

void Camera::shake(GSvector2 _scale)
{
	GSvector3 position;
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randX(0, _scale.x);
	std::uniform_int_distribution<> randY(0, _scale.y);
	float x = cos(randX(mt));
	float y = sin(randY(mt));

	position.x = cos(randX(mt));
	position.y = sin(randY(mt));
	position.z = 0;

	tracking_position_offset(position, 0.1f);
	tracking_target_offset(position, 0.1f);

	return;
}

void Camera::zoom_clamp(
	const float _min,
	const float _max
)
{
	//視野角の範囲を再設定
	m_fov_clamp.x = _min;
	m_fov_clamp.y = _max;

	return;
}

void Camera::zoom(const float _value)
{
	//視野角を再設定
	m_perspective.x = _value;
}

void Camera::zoom_in(const float _speed)
{
	//ズーム処理更新
	update_zoom(-_speed);
}

void Camera::zoom_out(const float _speed)
{
	//ズーム処理更新
	update_zoom(_speed);
}

const GSvector3& Camera::get_cameraTarget_player() const
{
	//保持したプレイヤーの位置を返す
	return m_cameraTarget_player->_target();
}

const GSvector3& Camera::get_cameraTarget_enemy() const
{
	//保持したエネミーの位置を返す
	return m_cameraTarget_enemy->_target();
}

const float Camera::get_direction_player(void) const
{
	return m_direction_player;
}

const bool Camera::isFrustumCulling(const GSvector3 & center, float radius) const
{
	//視錐台
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &m_lookAt->mat_view, &m_mat_projection);

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohterとカメラの距離
	float dis = ohter.distance(m_lookAt->position);
	//距離とnearの差
	return dis-(m_perspective.z + radius);
}

const float Camera::distance(const GSvector3 & ohter) const
{
	return m_lookAt->position.distance(ohter);
}

const Transform Camera::transform() const
{
	GSvector3 position = m_lookAt->position;
	//yaw回転だけ
 	GSvector3 vec= m_lookAt->target - position;
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), position);
}

const GSvector3 & Camera::position(void)
{
	//カメラの位置を返す
	return m_lookAt->position;
}

void Camera::tracking_position_offset(const GSvector3 & _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* position = &m_lookAt->position_offset;

	//３次元ベクトルの線形補間
	gsVector3Lerp(position, position, &_target, _speed);
}

void Camera::tracking_target_offset(const GSvector3 & _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* position = &m_lookAt->target_offset;

	//３次元ベクトルの線形補間
	gsVector3Lerp(position, position, &_target, _speed);
}

void Camera::update_perspective(void)
{
	//投射変換行列の設定
	glMatrixMode(GL_PROJECTION);

	//変換行列の初期化
	glLoadIdentity();

	//投射変換行列
	gluPerspective(
		m_perspective.x,
		m_perspective.y,
		m_perspective.z,
		m_perspective.w
	);

	//シェーダー用投射変換行列に現在の投射変換行列を代入
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&m_mat_projection);

	return;
}

void Camera::update_lookAt(void)
{
	//モデルビュー変換行列の設定
	glMatrixMode(GL_MODELVIEW);

	//モデルビュー変換行列の初期化
	glLoadIdentity();

	//いちいちm_lookAt呼ぶのがめんどくさいので宣言
	GSvector3 position	= m_lookAt->position + m_lookAt->position_offset;
	GSvector3 target	= m_lookAt->target + m_lookAt->target_offset;
	GSvector3 up		= m_lookAt->up;

	//モデルビュー変換行列
	gluLookAt(
		position.x,	position.y,	position.z,
		target.x,	target.y,	target.z,
		up.x,		up.y,		up.z
	);

	//シェーダー用モデルビュー変換行列に現在のモデルビュー行列を代入
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)&m_lookAt->mat_view);

	return;
}

void Camera::update_zoom(const float _value)
{
	Math::Clamp clamp;
	
	//視野角に値を足す
	m_perspective.x += _value;

	//視野角の値が範囲外に出ないようにする
	m_perspective.x = clamp(
		m_perspective.x,
		m_fov_clamp.x,
		m_fov_clamp.y
	);

	return;
}

void Camera::update_tracking(
	const GSvector3 & _position,
	const GSvector3 & _lookAt,
	const GSvector2 & _trackingSpeed)
{
	//カメラ位置の追尾処理
	tracking_position(_position, _trackingSpeed.x);

	//注視点の追尾処理
	tracking_lookAt(_lookAt, _trackingSpeed.y);
}

bool Camera::isHitGround(const Map& _map, GSvector3 * _intersectPos, GSvector3 * _position)
{
	//カメラが地面に当たっているかを調べる
	return _map.isCollisionRay((*_position), RAY_DONW, _intersectPos) &&
		_position->y < _intersectPos->y;
}