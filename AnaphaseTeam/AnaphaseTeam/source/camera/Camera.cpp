#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraTarget.h"
#include "../../header/math/Calculate.h"
#include "../../header/math/AMath.h"
#include "../../header/data/id/OCTREE_ID.h"
#include "../../header/map/Map.h"
#include "../../header/camera/LookAt.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/camera/Zoom.h"
#include <random>
#include <vector>

//コンストラクタ
Camera::Camera() :
	RAY_DONW(GSvector3(0, -1, 0)),
	R(0.5f),
	m_perspective(GSvector4(45.0f, 1280.0f / 720.0f, 0.3f, 1000.0f)),
	m_lookAt(std::make_unique<LookAt>(GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 1.0f, 0.0f))),
	m_rotate_dolly(0.0f, 0.0f),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>()),
	m_direction_player(0.0f),
	mZoom(std::make_unique<Zoom>())
{
	mZoom->init(m_perspective.x);
	
	gsMatrix4Identity(&m_mat_projection);
}

//デストラクタ
Camera::~Camera()
{
}

//初期化：オフセット
void Camera::initializeOffset(void)
{
	m_lookAt->position_offset = { 0.0f, 0.0f, 0.0f };
	m_lookAt->target_offset = { 0.0f, 0.0f, 0.0f };
}

//実行
void Camera::run(IRenderer* _renderer)
{
	update_perspective();
	//_renderer->perspective(m_perspective.x, m_perspective.y, m_perspective.z, m_perspective.w);

	update_lookAt();
	//_renderer->lookAt(m_lookAt->position, m_lookAt->target, m_lookAt->up);

	mZoom->update(&m_perspective.x);

	return;
}

//カメラワーク：ティルト・パン
void Camera::tiltPan(
	const GSvector3&	_position_camera,
	const GSvector2&	_rotate,
	const GSvector2&	_trackingSpeed
)
{
	//追尾処理更新
	update_tracking(
		_position_camera,
		AMath::ballRotate(m_lookAt->position, _rotate, 10),	//球面座標を利用した回転
		_trackingSpeed
	);
}

//カメラワーク：ドリー
void Camera::dolly(
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
	GSvector3 position = AMath::ballRotate(
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

//設定：カメラの位置
void Camera::set_cameraTarget_player(const GSvector3& _target)
{
	//プレイヤーの位置を保持
	m_cameraTarget_player->lookAt(_target);
}

//設定：ターゲットの位置
void Camera::set_cameraTarget_enemy(const GSvector3& _target)
{
	//エネミーの位置を保持
	m_cameraTarget_enemy->lookAt(_target);
}

//設定：プレイヤーの方位角
void Camera::set_direction_player(float _direction)
{
	//プレイヤーの方位角を保持
	m_direction_player = _direction;
}

//追尾：カメラの位置
void Camera::tracking_position(const GSvector3& _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* position = &m_lookAt->position;

	//３次元ベクトルの線形補間
	gsVector3Lerp(position, position, &_target, _speed);
}

//追尾：カメラの位置のオフセット
void Camera::tracking_positionOffset(const GSvector3 & _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* position = &m_lookAt->position_offset; 

	//３次元ベクトルの線形補間
	gsVector3Lerp(position, position, &_target, _speed);
}

//追尾：注視点
void Camera::tracking_lookAt(const GSvector3& _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* target = &m_lookAt->target;

	//３次元ベクトルの線形補間
	gsVector3Lerp(target, target, &_target, _speed);
}

//追尾：注視点のオフセット
void Camera::tracking_lookAtOffset(const GSvector3 & _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* target = &m_lookAt->target_offset;

	//３次元ベクトルの線形補間
	gsVector3Lerp(target, target, &_target, _speed);
}

//地面とのあたり判定
void Camera::collisionGround(const Map & _map)
{
	//これにレイのヒットした位置が保持される
	GSvector3 intersectPos;

	//カメラが地面に当たっていたら
	//カメラの位置を修正
	if (isHitGround(_map, &m_lookAt->position))
	{
		m_lookAt->position.y = m_intersectPos.y;
	}
}

//取得：プレイヤー位置
const GSvector3& Camera::get_cameraTarget_player() const
{
	//保持したプレイヤーの位置を返す
	return m_cameraTarget_player->_target();
}

//取得：敵の位置
const GSvector3& Camera::get_cameraTarget_enemy() const
{
	//保持したエネミーの位置を返す
	return m_cameraTarget_enemy->_target();
}

//取得：プレイヤーの方位角
const float Camera::get_direction_player(void) const
{
	return m_direction_player;
}

//見えてないオブジェクトは描画しない
const bool Camera::isFrustumCulling(const GSvector3 & center, float radius) const
{
	//視錐台
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &m_lookAt->mat_view, &m_mat_projection);

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

//近クリップとの距離
const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohterとカメラの距離
	float dis = ohter.distance(m_lookAt->position);
	//距離とnearの差
	return dis-(m_perspective.z + radius);
}

//カメラとの距離
const float Camera::distance(const GSvector3 & ohter) const
{
	return m_lookAt->position.distance(ohter);
}

//カメラのトランスフォーム
const Transform Camera::transform() const
{
	GSvector3 position = m_lookAt->position;
	//yaw回転だけ
 	GSvector3 vec= m_lookAt->target - position;
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), position);
}

//カメラの位置を返す
const GSvector3 & Camera::position(void)
{
	//カメラの位置を返す
	return m_lookAt->position;
}

Zoom * Camera::zoom()
{
	return mZoom.get();
}

//追尾：カメラの位置のオフセット
void Camera::tracking_position_offset(const GSvector3 & _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* position = &m_lookAt->position_offset;
	//３次元ベクトルの線形補間
	gsVector3Lerp(position, position, &_target, _speed);
}

//追尾：注視点のオフセット
void Camera::tracking_target_offset(const GSvector3 & _target, float _speed)
{
	//見やすくするために宣言
	GSvector3* position = &m_lookAt->target_offset;
	//３次元ベクトルの線形補間
	gsVector3Lerp(position, position, &_target, _speed);
}

//パースペクティブの更新
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

//ルックアットの更新
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
}

//追尾の更新
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

//地面と当たったか？
bool Camera::isHitGround(const Map& _map, GSvector3 * _position)
{
	GSvector3 intersectPos;

	if (_map.isCollisionRay((*_position), RAY_DONW, &intersectPos)) {
		m_intersectPos = intersectPos + GSvector3(0, R, 0);
	}
	
	if (m_intersectPos.y > m_lookAt->position.y) {
		return true;
	}

	return false;
}