#include "../../header/shape/AABB.h"
#include "../../header/renderer/Renderer.h"
#include <cmath>
#include "../../header/shape/Sphere.h"
#include "../../header/shape/OBB.h"
#include "../../header/shape/Segment.h"
AABB::AABB(const GSvector3 & _position, const GSvector3 & _radius)
	:m_position(_position), m_radius(_radius)
{
}

AABB::~AABB()
{
}

const bool AABB::isCollision(const Sphere * _sphere) const
{
	return _sphere->isCollision(this);
}

const bool AABB::isCollision(const Capsule * _capsule) const
{
	return false;
}

const bool AABB::isCollision(const Segment * _segment) const
{
	GSvector3 intercept;
	GSvector3 begin = _segment->begin();
	if (!isCollision_Ray(begin, _segment->vector(), &intercept))
	{
		return false;
	}
	float dis_End = begin.distance(_segment->end());
	float dis_I = intercept.distance(begin);
	return dis_I<=dis_End;
}

const bool AABB::isCollision(const OBB * _obb) const
{
	return _obb->isCollisionAABB(m_position, m_radius);
}

const bool AABB::isCollision(const AABB * _aabb) const
{
	return min().x < _aabb->max().x && max().x > _aabb->min().x
		&& min().y < _aabb->max().y && max().y > _aabb->min().y
		&& min().z < _aabb->max().z && max().z > _aabb->min().z;
}

const bool AABB::isCollision(const Shape * _shape) const
{
	return _shape->isCollision(this);
}

void AABB::draw(const Renderer & renderer, const GScolor & color)
{
	renderer.getDraw3D().drawBox(&m_position, &m_radius, &GSvector3(0, 0, 0), color);
}

const bool AABB::isCollisionSphere(const GSvector3 & _center, float _radius) const
{
	return distance_point(_center) <= _radius;
}

const float AABB::distance_point(const GSvector3 & _point) const
{
	// 長さのべき乗の値を格納
	float sqLen = 0;
	for (int i = 0; i < 3; i++)
	{
		// 各軸で点が最小値以下もしくは最大値以上ならば、差を考慮
		if (_point.v[i] < min().v[i])
		{
			sqLen += (_point.v[i] - min().v[i]) * (_point.v[i] - min().v[i]);
		}

		if (_point.v[i] > max().v[i])
		{
			sqLen += (_point.v[i] - max().v[i]) * (_point.v[i] - max().v[i]);
		}

	}
	return std::sqrt(sqLen);
}

const GSvector3 AABB::min() const
{
	return m_position - m_radius;
}

const GSvector3 AABB::max() const
{
	return m_position + m_radius;
}
