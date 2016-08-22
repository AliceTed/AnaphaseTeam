#include "..\..\header\shape\Segment.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/shape/Sphere.h"
#include "../../header/shape/Capsule.h"
#include "../../header/shape/OBB.h"
Segment::Segment(const GSvector3& _begin, const GSvector3& _vector)
	:m_begin(_begin), m_vector(_vector)
{
}

Segment::~Segment()
{
}

//const bool Segment::isCollision(const Ray * _ray) const
//{
//	return gsCollisionLineAndLine;
//}

const bool Segment::isCollision(const Sphere * _sphere) const
{
	return _sphere->isCollision(this);
}

const bool Segment::isCollision(const Capsule * _capsule) const
{
	return _capsule->isCollision(this);
}

const bool Segment::isCollision(const Segment * _segment) const
{
	return gsCollisionLineAndLine(&m_begin,&end(),&_segment->m_begin,&_segment->end(),GS_FALSE, 1.0f, &GSvector3(), &GSvector3())==GS_TRUE;
}

const bool Segment::isCollision(const OBB * _obb) const
{
	return false;
}

const bool Segment::isCollision(const Shape * _shape) const
{
	return _shape->isCollision(this);
}

void Segment::draw(const Renderer & renderer, const GScolor & color)
{
	renderer.getDraw3D().drawLine(&m_begin,&end(),color);
}

const bool Segment::isCollisionSphere(const GSvector3& _center, float _radius) const
{
	return gsCollisionSphereAndLine(&_center,_radius,&m_begin,&end(),NULL)==GS_TRUE;
}

const bool Segment::isCollisionCapsule(const Segment & _other, float _radius) const
{
	return gsCollisionLineAndLine(&m_begin, &end(), &_other.m_begin, &_other.end(), GS_FALSE, _radius,&GSvector3(), &GSvector3()) == GS_TRUE;
}

const GSvector3& Segment::vector() const
{
	return m_vector;
}

const GSvector3 Segment::end() const
{
	return m_begin+m_vector;
}

const GSvector3& Segment::begin() const
{
	return m_begin;
}
