#include "../../header/shape/OBB.h"
#include "../../header/renderer/Renderer.h"
#include "../../header/shape/Sphere.h"
#include "../../header/shape/Segment.h"
#include "../../header/shape/Capsule.h"
OBB::OBB(const GSvector3 & _position, const GSvector3 & _radius, const GSvector3 & _rotate)
	:m_position(_position), m_radius(_radius), m_rotate(_rotate)
{
	rotateToAxis();
}

OBB::~OBB()
{
}
void OBB::rotateToAxis()
{
	GSmatrix4 mRot;
	gsMatrix4YawPitchRoll(&mRot, m_rotate.y, m_rotate.x, m_rotate.z);
	m_axisX = mRot*GSvector3(1, 0, 0);
	m_axisY = mRot*GSvector3(0, 1, 0);
	m_axisZ = mRot*GSvector3(0, 0, 1);
}

const bool OBB::isCollisionSphere(const GSvector3 & _center, float _radius) const
{
	//中心点との最短距離が半径以下なら衝突
	return distance_point(_center) <= _radius;
}

const bool OBB::isCollision(const Sphere * _sphere) const
{
	return _sphere->isCollision(this);
}

const bool OBB::isCollision(const Capsule * _capsule) const
{
	return _capsule->isCollision(this);
}

const bool OBB::isCollision(const Segment * _segment) const
{
	return _segment->isCollision(this);
}

const bool OBB::isCollision(const OBB * _obb) const
{
	// 中心間の距離ベクトル算出
	GSvector3 distance = _obb->m_position - m_position;
	return axisCompare(_obb, distance);
}

const bool OBB::isCollision(const AABB * _aabb) const
{
	return false;
}

const bool OBB::isCollision(const Shape * _shape) const
{
	return _shape->isCollision(this);
}

const bool OBB::compareLengthOBB(const OBB * _other, const GSvector3 vSep, const GSvector3 vDistance) const
{
	// 分離軸上のAからBの距離
	float length = fabsf(vSep.dot(vDistance));

	// 分離軸上でAから最も遠いAの頂点までの距離
	float lenA = farthestDistance(vSep);

	// 分離軸上でBから最も遠いBの頂点までの距離
	float lenB = _other->farthestDistance(vSep);

	if (length > lenA + lenB)
	{
		return false;
	}
	return true;
}

const float OBB::farthestDistance(const GSvector3 & _vSeq)const
{
	float x = fabsf(m_axisX.dot(_vSeq)*m_radius.x);
	float y = fabsf(m_axisY.dot(_vSeq)*m_radius.y);
	float z = fabsf(m_axisZ.dot(_vSeq)*m_radius.z);
	return x + y + z;
}


const bool OBB::parallel_Slab_Segment(float _radius, float _dir, float _pos) const
{
	float EPSILON = 5.0f;
	float l = _radius;
	if (abs(_dir) < EPSILON)
	{
		if (abs(_pos / l) > 1.0)
		{
			return false;
		}
		return true;
	}

	float t1 = (-l - _pos) / _dir;
	float t2 = (l - _pos) / _dir;

	if (t1 > t2)
	{
		std::swap(t1, t2);
	}

	float tmin = 0.0;
	float tmax = 1.0;

	if (t1 > tmin)
	{
		tmin = t1;
	}
	if (t2 < tmax)
	{
		tmax = t2;
	}
	if (tmin > tmax)
	{
		return false;
	}
	return true;
}

const bool OBB::each_Slab_Segment(const GSvector3& _radius, const GSvector3 & _dir, const GSvector3 & _pos, const GSvector3& _axis) const
{
	//線分の始点をOBBの中心座標分ずらす
	GSvector3 segPos = _pos - m_position;
	segPos = segPos.cross(_axis);
	GSvector3 segDir = _dir.cross(_axis);

	for (int i = 0; i < 3; ++i)
	{
		if (!parallel_Slab_Segment(_radius.v[i], segDir.v[i], segPos.v[i]))
		{
			return false;
		}
	}
	return true;
}


const bool OBB::axisCompare(const OBB * _other, const GSvector3 & _distance) const
{
	// 分離軸を比較
	if (!selfAxisCompare(_other, _distance))return false;
	if (!otherAxisCompare(_other, _distance))return false;

	// 分離軸同士の外積を比較
	if (!crossAxisCompare(_other, _distance))return false;

	return true;
}

const bool OBB::selfAxisCompare(const OBB* _other, const GSvector3 & _distance) const
{
	if (!compareLengthOBB(_other, m_axisX, _distance)) return false;
	if (!compareLengthOBB(_other, m_axisY, _distance)) return false;
	if (!compareLengthOBB(_other, m_axisZ, _distance)) return false;

	return true;
}

const bool OBB::otherAxisCompare(const OBB * _other, const GSvector3 & _distance) const
{
	if (!compareLengthOBB(_other, _other->m_axisX, _distance)) return false;
	if (!compareLengthOBB(_other, _other->m_axisY, _distance)) return false;
	if (!compareLengthOBB(_other, _other->m_axisZ, _distance)) return false;

	return true;
}

const bool OBB::crossAxisCompare(const OBB * _other, const GSvector3 & _distance) const
{
	GSvector3 vSep;

	vSep = m_axisX.cross(_other->m_axisX);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisX.cross(_other->m_axisY);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisX.cross(_other->m_axisZ);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisY.cross(_other->m_axisX);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisY.cross(_other->m_axisY);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisY.cross(_other->m_axisZ);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisZ.cross(_other->m_axisX);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisZ.cross(_other->m_axisY);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	vSep = m_axisZ.cross(_other->m_axisZ);
	if (!compareLengthOBB(_other, vSep, _distance)) return false;

	return true;
}

void OBB::draw(const Renderer & renderer, const GScolor & color)
{
	renderer.getDraw3D().drawBox(&m_position, &m_radius, &m_rotate, color);
}
const bool OBB::isCollisionSegment(const GSvector3& _begin, const GSvector3& _vector) const
{
	return each_Slab_Segment(m_radius, _vector, _begin, m_axisX)&&
		each_Slab_Segment(m_radius, _vector, _begin, m_axisY) &&
		each_Slab_Segment(m_radius, _vector, _begin, m_axisZ);
}
const bool OBB::isCollisionCapsule(const GSvector3 & _position, const GSvector3 & _vector, float _radius)const
{
	GSvector3 radius = m_radius + GSvector3(_radius, _radius, _radius);
	return each_Slab_Segment(radius, _vector, _position, m_axisX)&&
		each_Slab_Segment(radius, _vector, _position, m_axisY) &&
		each_Slab_Segment(radius, _vector, _position, m_axisZ)||
		isCollisionSphere(_position,_radius)||
		isCollisionSphere(_position+_vector, _radius);
}
const bool OBB::isCollisionAABB(const GSvector3 & _position, const GSvector3 & _radius) const
{
	OBB other(_position, _radius, GSvector3(0, 0, 0));
	return isCollision(&other);
}
const GSvector3 OBB::axisProtrudedVector(const GSvector3 & _axis, float _radius, const GSvector3 & _point) const
{
	if (_radius <= 0)return GSvector3(0, 0, 0);  // L=0は計算できな
	float s = (_point - m_position).dot(_axis) / _radius;
	// sの値から、はみ出した部分があればそのベクトルを加算
	s = fabs(s);
	if (s <= 1)return GSvector3(0, 0, 0);

	// はみ出した部分のベクトル算出
	return (1 - s)*_radius*_axis;
}

const float OBB::distance_point(const GSvector3 & _point) const
{
	// 最終的に長さを求めるベクトル
	GSvector3 v(0, 0, 0);

	v += axisProtrudedVector(m_axisX, m_radius.x, _point);
	v += axisProtrudedVector(m_axisY, m_radius.y, _point);
	v += axisProtrudedVector(m_axisZ, m_radius.z, _point);
	return v.length();
}
