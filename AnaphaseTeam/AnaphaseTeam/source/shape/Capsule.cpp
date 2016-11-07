#include "../../header/shape/Capsule.h"
#include "../../header/renderer/Renderer.h"

#include "../../header/shape/Sphere.h"
#include "../../header/math/Calculate.h"
#include "../../header/collision/Hit.h"
Capsule::Capsule(const Segment & _segment, float _radius)
	:m_Segment(_segment),m_Radius(_radius)
{
}

Capsule::~Capsule()
{
}

void Capsule::translate(const GSvector3 & _position)
{
	m_Segment.translate(_position);
}

void Capsule::transfer(const GSvector3 & _position)
{
	m_Segment.transfer(_position);
}

//const bool Capsule::isCollision(const Ray * _ray) const
//{
//	return false;
//}

const bool Capsule::isCollision(const Sphere * _sphere, Hit* _hit) const
{
	return _sphere->isCollision(this,_hit);
}

const bool Capsule::isCollision(const Capsule * _capsule, Hit* _hit) const
{
	return gsCollisionCupsuleAndCupsule
		(
			&m_Segment.begin(),&m_Segment.end(),m_Radius,
			&_capsule->m_Segment.begin(),&_capsule->m_Segment.end(),_capsule->m_Radius
			,NULL,&_hit->m_intersect
		)==GS_TRUE;
}

const bool Capsule::isCollision(const Segment * _segment, Hit* _hit) const
{
	return _segment->isCollisionCapsule(m_Segment,m_Radius, _hit);
}

const bool Capsule::isCollision(const Shape * _shape, Hit* _hit) const
{
	return _shape->isCollision(this,_hit);
}
void Capsule::draw(const Renderer & renderer, const GScolor& color)
{
	GSvector3 v = m_Segment.vector();
	float ele =v.getPitch();
	
	Math::ATan aTan;
	float dir = aTan(v.x, v.z);
	renderer.getDraw3D().drawCapsule(&m_Segment.begin(), m_Radius, v.length(), dir, ele,color);
}

const bool Capsule::isCollisionSphere(const GSvector3 & _center, float _radius, Hit* _hit) const
{
	return m_Segment.isCollisionSphere(_center,_radius+m_Radius,_hit);
}
