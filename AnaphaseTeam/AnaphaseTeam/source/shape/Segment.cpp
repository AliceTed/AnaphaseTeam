#include "..\..\header\shape\Segment.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/shape/Sphere.h"
#include "../../header/shape/Capsule.h"
Segment::Segment(const GSvector3& _begin, const GSvector3& _vector)
	:m_begin(_begin), m_vector(_vector)
{
}

Segment::~Segment()
{
}

void Segment::translate(const GSvector3 & _position)
{
	m_begin += _position;
}

void Segment::transfer(const GSvector3 & _position)
{
	m_begin = _position;
}

//const bool Segment::isCollision(const Ray * _ray) const
//{
//	return gsCollisionLineAndLine;
//}

const bool Segment::isCollision(const Sphere * _sphere, GSvector3* _out) const
{
	return _sphere->isCollision(this, _out);
}

const bool Segment::isCollision(const Capsule * _capsule, GSvector3* _out) const
{
	return _capsule->isCollision(this, _out);
}

const bool Segment::isCollision(const Segment * _segment, GSvector3* _out) const
{
	return gsCollisionLineAndLine(&m_begin, &end(), &_segment->m_begin, &_segment->end(), GS_FALSE, 1.0f, &GSvector3(), &GSvector3()) == GS_TRUE;
}
const bool Segment::isCollision(const Shape * _shape, GSvector3* _out) const
{
	return _shape->isCollision(this, _out);
}

void Segment::draw(const Renderer & renderer, const GScolor & color)
{
	renderer.getDraw3D().drawLine(&m_begin, &end(), color, 2);
}

const bool Segment::isCollisionSphere(const GSvector3& _center, float _radius, GSvector3* _out) const
{
	return gsCollisionSphereAndLine(&_center, _radius, &m_begin, &end(), _out) == GS_TRUE;
}

const bool Segment::isCollisionCapsule(const Segment & _other, float _radius, GSvector3* _out) const
{
	return gsCollisionLineAndLine(&m_begin, &end(), &_other.m_begin, &_other.end(), GS_FALSE, _radius, _out, &GSvector3()) == GS_TRUE;
}

const GSvector3& Segment::vector() const
{
	return m_vector;
}

const bool Segment::isONPoint(const GSvector3 & _point) const
{
	if (m_begin == _point)
	{
		return true;
	}
	GSvector3 v = m_vector;
	v = v.normalize();
	GSvector3 pv = _point - m_begin;
	pv = pv.normalize();
	//•ûŒü‚ªˆá‚Á‚½‚çü•ªã‚Å‚Í‚È‚¢
	if (v != pv)
	{
		return false;
	}
	return v.length() <= pv.length();
}

const GSvector3 Segment::end() const
{
	return m_begin + m_vector;
}

const GSvector3& Segment::begin() const
{
	return m_begin;
}
