#include "camera/LookAt.h"
#include "renderer/IRenderer.h"
#include "function/Tracking.h"
#include "math/AMath.h"
#include "math/Calculate.h"
#include "map/Map.h"

//�f�t�H���g�R���X�g���N�^
LookAt::LookAt() :
	mPos(0.f, 0.f, 0.f),
	mPosOffset(0.f, 0.f, 0.f),
	mLookPos(0.f, 0.f, 0.f),
	mLookPosOffset(0.f, 0.f, 0.f),
	mUp(0.f, 1.f, 0.f),
	mMatView(),
	mRotateDolly(0.f, 0.f)
{
	gsMatrix4Identity(&mMatView);
}

//�f�X�g���N�^
LookAt::~LookAt()
{
}

//������
void LookAt::init(const GSvector3 & _pos, const GSvector3 & _lookPos, const GSvector3 & _up)
{
	mPos = _pos;
	mLookPos = _lookPos;
	mPosOffset = GSvector3(0.f, 0.f, 0.f);
	mLookPosOffset = GSvector3(0.f, 0.f, 0.f);
	mUp = _up;
	mRotateDolly = GSvector2(0.f, 0.f);
	gsMatrix4Identity(&mMatView);
}

//�X�V
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

//�X�V�i�����_���[�j
void LookAt::update(IRenderer * _renderer)
{
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	GSvector3 pos = mPos + mPosOffset;
	GSvector3 lookPos = mLookPos + mLookPosOffset;

	gluLookAt(
		pos.x, pos.y, pos.z,
		lookPos.x, lookPos.y, lookPos.z,
		mUp.x, mUp.y, mUp.z
	);

	_renderer->lookAt(pos, lookPos, mPos);

	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)&mMatView);
}

//�J�����̈ړ�
void LookAt::move(const GSvector3 _target, float _speed)
{
	Tracking::tracking(&mPos, _target, _speed);
}

//�J�����̒����_��ύX
void LookAt::lookAt(const GSvector3 & _target, float _speed)
{
	Tracking::tracking(&mLookPos, _target, _speed);
}

//�e�B���g�E�p��
void LookAt::titlePan(const GSvector3 & _pos, const GSvector2 & _rotate, const GSvector2 & _speed)
{
	move(_pos, _speed.x);

	lookAt(AMath::ballRotate(mPos, _rotate, 10), _speed.y);
}

//�h���[
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

//�n�ʂƂ̂����蔻��
void LookAt::collisionGround(const Map & _map)
{
	if (isHitGround(_map, &mPos)) {
		mPos.y = mIntersectPos.y;
	}
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
	//yaw��]����
	GSvector3 vec = mLookPos - mPos;
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), mPos);
}

//�n�ʂƓ���������
bool LookAt::isHitGround(const Map & _map, GSvector3 * _pos)
{
	GSvector3 intersectPos;
	if (_map.isCollisionRay((*_pos), GSvector3(0.f, -1.f, 0.f), &intersectPos)) {
		mIntersectPos = intersectPos + GSvector3(0.f, 0.5f, 0.f);
	}

	if (mIntersectPos.y > mPos.y) {
		return true;
	}
	return false;
}
