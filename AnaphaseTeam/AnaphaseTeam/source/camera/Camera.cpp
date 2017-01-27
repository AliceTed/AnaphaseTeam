#include "camera/Camera.h"
#include "camera/CameraTarget.h"
#include "math/Calculate.h"
#include "math/AMath.h"
#include "data/id/OCTREE_ID.h"
#include "map/Map.h"
#include "camera/LookAt.h"
#include "renderer/IRenderer.h"
#include "camera/Perspective.h"
#include "camera/Zoom.h"
#include "function/Tracking.h"
#include <random>
#include <vector>

//コンストラクタ
Camera::Camera() :
	RAY_DONW(GSvector3(0, -1, 0)),
	R(0.5f),
	mPerspective(std::make_unique<Perspective>()),
	m_lookAt(std::make_unique<LookAt>(GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 0.0f, 0.0f), GSvector3(0.0f, 1.0f, 0.0f))),
	m_rotate_dolly(0.0f, 0.0f),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>()),
	m_direction_player(0.0f)
{
	mPerspective->init(GSvector4(45.f, 1280.f / 720.f, 0.3f, 1000.f));
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
	mPerspective->update();

	update_lookAt();
	//_renderer->lookAt(m_lookAt->position, m_lookAt->target, m_lookAt->up);

	return;
}

//カメラワーク：ティルト・パン
void Camera::tiltPan(
	const GSvector3&	_position_camera,
	const GSvector2&	_rotate,
	const GSvector2&	_trackingSpeed
)
{
	move(_position_camera, _trackingSpeed.x);

	lookAt(AMath::ballRotate(m_lookAt->position, _rotate, 10), _trackingSpeed.y);
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

	move(position, _trackingSpeed.x);

	lookAt(_position_target, _trackingSpeed.y);

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
void Camera::move(const GSvector3& _target, float _speed)
{
	GSvector3* position = &m_lookAt->position;
	Tracking::tracking(position, _target, _speed);
}

//追尾：注視点
void Camera::lookAt(const GSvector3& _target, float _speed)
{
	GSvector3* target = &m_lookAt->target;
	Tracking::tracking(target, _target, _speed);
}

//地面とのあたり判定
void Camera::collisionGround(const Map & _map)
{
	if (isHitGround(_map, &m_lookAt->position))
	{
		m_lookAt->position.y = m_intersectPos.y;
	}
}

//取得：プレイヤー位置
const GSvector3& Camera::get_cameraTarget_player() const
{
	return m_cameraTarget_player->_target();
}

//取得：敵の位置
const GSvector3& Camera::get_cameraTarget_enemy() const
{
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
	gsFrustumFromMatrices(&frustum, &m_lookAt->mat_view, &mPerspective->matProjective());

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

//近クリップとの距離
const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohterとカメラの距離
	float dis = ohter.distance(m_lookAt->position);
	//距離とnearの差
	return dis-(mPerspective->near() + radius);
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
	return m_lookAt->position;
}

Perspective * Camera::perspective()
{
	return mPerspective.get();
}

//追尾：カメラの位置のオフセット
void Camera::moveOffset(const GSvector3 & _target, float _speed)
{
	GSvector3* position = &m_lookAt->position_offset;
	Tracking::tracking(position, _target, _speed);
}

//追尾：注視点のオフセット
void Camera::lookAtOffset(const GSvector3 & _target, float _speed)
{
	GSvector3* position = &m_lookAt->target_offset;
	Tracking::tracking(position, _target, _speed);
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