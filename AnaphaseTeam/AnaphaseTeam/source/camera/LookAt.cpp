#include "camera/LookAt.h"
#include "renderer/IRenderer.h"
#include "function/Tracking.h"
#include "math/AMath.h"
#include "math/Calculate.h"
#include "map/Map.h"

//デフォルトコンストラクタ
LookAt::LookAt() :
	mPos(0.f, 0.f, 0.f),
	mPosOffset(0.f, 0.f, 0.f),
	mLookPos(0.f, 0.f, 0.f),
	mLookPosOffset(0.f, 0.f, 0.f),
	mUp(0.f, 1.f, 0.f),
	mMatView(),
	mRotateDolly(0.f, 0.f),
	mIntersectPos(0.f, 0.f, 0.f),
	m_front(0.f),
	m_back(0.f),
	m_left(0.f),
	m_right(0.f)
{
	gsMatrix4Identity(&mMatView);
}

//デストラクタ
LookAt::~LookAt()
{
}

//初期化
void LookAt::init(const GSvector3 & _pos, const GSvector3 & _lookPos, const GSvector3 & _up)
{
	mPos = _pos;
	mLookPos = _lookPos;
	mPosOffset = GSvector3(0.f, 0.f, 0.f);
	mLookPosOffset = GSvector3(0.f, 0.f, 0.f);
	mUp = _up;
	mRotateDolly = GSvector2(0.f, 0.f);
	gsMatrix4Identity(&mMatView);
	mIntersectPos = _pos;
}

//更新
void LookAt::update()
{
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	GSvector3 pos = mPos + mPosOffset;
	GSvector3 lookPos = mLookPos + mLookPosOffset;;

	gluLookAt(
		pos.x, pos.y, pos.z,
		lookPos.x, lookPos.y, lookPos.z,
		mUp.x, mUp.y, mUp.z
	);

	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)&mMatView);
}

//更新（レンダラー）
void LookAt::update(IRenderer * _renderer)
{
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	GSvector3 pos = mPos + mPosOffset;
	GSvector3 lookPos = mLookPos + mLookPosOffset;

	_renderer->lookAt(pos, lookPos, mPos);
}

//カメラの移動
void LookAt::move(const GSvector3 _target, float _speed)
{
	Tracking::tracking(&mPos, _target, _speed);
}

//カメラの注視点を変更
void LookAt::lookAt(const GSvector3 & _target, float _speed)
{
	Tracking::tracking(&mLookPos, _target, _speed);
}

//ティルト・パン
void LookAt::titlePan(const GSvector3 & _pos, const GSvector2 & _rotate, const GSvector2 & _speed)
{
	move(_pos, _speed.x);

	lookAt(AMath::ballRotate(mPos, _rotate, 10), _speed.y);
}

//ドリー
void LookAt::dolly(const GSvector3 & _center, const GSvector2 _rotate, const float _distance, const GSvector2 & _speed)
{
	AMath::lerp_eleDir(&mRotateDolly, _rotate, _speed.x);

	float x = Math::Calculate::degTorad(mRotateDolly.x);
	float y = Math::Calculate::degTorad(mRotateDolly.y);
	GSvector3 pos = AMath::ballRotate(
		_center,
		GSvector2(x, y),
		_distance
	);

	move(pos, _speed.x);

	lookAt(_center, _speed.y);
}

//地面とのあたり判定
void LookAt::collisionGround(const Map & _map)
{
	isHitGround(_map);
}

GSmatrix4 LookAt::matView()
{
	return mMatView;
}

const GSvector3 & LookAt::position()
{
	return mPos;
}

const GSvector3 & LookAt::lookPosition()
{
	return mLookPos;
}

const float LookAt::distance(const GSvector3 & _other) const
{
	return mPos.distance(_other);
}

const Transform LookAt::transform() const
{
	//yaw回転だけ
	GSvector3 vec = mLookPos - mPos;
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), mPos);
}

//地面と当たったか
void LookAt::isHitGround(const Map & _map)
{
	GSvector3 intersectPos;
	GSvector3 velocity = mLookPos - mPos;

	if (_map.isCollisionRay(mLookPos, GSvector3(0.f, -1.f, -15.f), &intersectPos)) {
		m_front = intersectPos.z;
	}
	if (_map.isCollisionRay(mLookPos, GSvector3(0.f, -1.f, 15.f), &intersectPos)) {
		m_back = intersectPos.z;
	}
	if (_map.isCollisionRay(mLookPos, GSvector3(-15.f, -1.f, 0.f), &intersectPos)) {
		m_left = intersectPos.x;
	}
	if (_map.isCollisionRay(mLookPos, GSvector3(15.f, -1.f, 0.f), &intersectPos)) {
		m_right = intersectPos.x;
	}

	if (_map.isCollisionRay(mPos, GSvector3(0.f, -1.f, 0.f), &intersectPos)) {
		mIntersectPos = intersectPos + GSvector3(0.f, 0.5f, 0.f);
	}

	bool bottom2 = mIntersectPos.y > mPos.y;
	bool left2 = m_left > mPos.x;
	bool right2 = m_right < mPos.x;
	bool front2 = m_front > mPos.z;
	bool back2 = m_back < mPos.z;

	

	if (left2) {
		mPos.x = m_left;
	}
	if (right2) {
		mPos.x = m_right;
	}
	if (front2) {
		mPos.z = m_front;
	}
	if (back2) {
		mPos.z = m_back;
	}
	if (bottom2) {
		mPos.y = mIntersectPos.y;
	}
}
