#include "../../header/shape/Capsule.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/shape/Sphere.h"
#include "../../header/shape/OBB.h"
#include "../../header/math/Calculate.h"
Capsule::Capsule(const Segment & _segment, float _radius)
	:m_Segment(_segment),m_Radius(_radius)
{
}

Capsule::~Capsule()
{
}

//const bool Capsule::isCollision(const Ray * _ray) const
//{
//	return false;
//}

const bool Capsule::isCollision(const Sphere * _sphere) const
{
	return _sphere->isCollision(this);
}

const bool Capsule::isCollision(const Capsule * _capsule) const
{
	return gsCollisionCupsuleAndCupsule
		(
			&m_Segment.begin(),&m_Segment.end(),m_Radius,
			&_capsule->m_Segment.begin(),&_capsule->m_Segment.end(),_capsule->m_Radius
			,NULL,NULL
		)==GS_TRUE;
}

const bool Capsule::isCollision(const Segment * _segment) const
{
	return _segment->isCollisionCapsule(m_Segment,m_Radius);
}

const bool Capsule::isCollision(const OBB * _obb) const
{
	return false;
}

const bool Capsule::isCollision(const Shape * _shape) const
{
	return _shape->isCollision(this);
}
void Capsule::draw(const Renderer & renderer, const GScolor& color)
{
	GSvector3 v = m_Segment.vector();
	float ele =v.getPitch();
	
	Math::ATan aTan;
	float dir = aTan(v.x, v.z);
	renderer.getDraw3D().drawCapsule(&m_Segment.begin(), m_Radius, v.length(), dir, ele,color);
}

const bool Capsule::isCollisionSphere(const GSvector3 & _center, float _radius) const
{
	return m_Segment.isCollisionSphere(_center,_radius+m_Radius);
}
