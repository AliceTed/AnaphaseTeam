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
	mLookAt(std::make_unique<LookAt>()),
	m_rotate_dolly(0.0f, 0.0f),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>()),
	m_direction_player(0.0f)
{
	mPerspective->init(GSvector4(45.f, 1280.f / 720.f, 0.3f, 1000.f));
	mLookAt->init(GSvector3(0.f, 0.f, 0.f), GSvector3(0.f, 0.f, 0.f));
}

//デストラクタ
Camera::~Camera()
{
}

//実行
void Camera::run(IRenderer* _renderer)
{
	mPerspective->update();

	mLookAt->update();

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

//地面とのあたり判定
void Camera::collisionGround(const Map & _map)
{
	mLookAt->collisionGround(_map);
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
	gsFrustumFromMatrices(&frustum, &mLookAt->matView(), &mPerspective->matProjective());

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}

//近クリップとの距離
const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohterとカメラの距離
	float dis = ohter.distance(mLookAt->position());
	//距離とnearの差
	return dis-(mPerspective->near() + radius);
}

//カメラとの距離
const float Camera::distance(const GSvector3 & ohter) const
{
	return mLookAt->distance(ohter);
}

//カメラのトランスフォーム
const Transform Camera::transform() const
{
	return mLookAt->transform();
}

//カメラの位置を返す
const GSvector3 & Camera::position(void)
{
	return mLookAt->position();
}

//パースペクティブを取得する
Perspective * Camera::perspective()
{
	return mPerspective.get();
}

//ルックアットを取得する
LookAt * Camera::lookAt()
{
	return mLookAt.get();
}
