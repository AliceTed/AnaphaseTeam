#include "../../header/shape/Sphere.h"

#include "../../header/renderer/Renderer.h"
#include "../../header/camera/Camera.h"
#include "../../header/map/Map.h"

//#include "../../header/shape/Ray.h"
#include "../../header/shape/Capsule.h"
#include "../../header/shape/Segment.h"
#include "../../header/collision/Hit.h"
Sphere::Sphere(const GSvector3& center, float radius)
	:center(center), radius(radius)
{
}

Sphere::~Sphere()
{
}

void Sphere::expand(float radius)
{
	this->radius += radius;
}

void Sphere::translate(const GSvector3 & _position)
{
	center += _position;
}

void Sphere::transfer(const GSvector3 & _position)
{
	center = _position;
}


//const bool Sphere::isCollision(const Ray * _ray) const
//{
//	return _ray->isCollisionSphere(center,radius);
//}

const bool Sphere::isCollision(const Sphere * _sphere, Hit* _hit) const
{
	GSvector3 v = center - _sphere->center;
	v.normalize();
	_hit->m_intersect= v*radius;
	return center.distance(_sphere->center) <radius + _sphere->radius;
}

const bool Sphere::isCollision(const Capsule * _capsule, Hit* _hit) const
{	
	return _capsule->isCollisionSphere(center,radius, _hit);
}

const bool Sphere::isCollision(const Segment * _segment, Hit* _hit) const
{	
	return _segment->isCollisionSphere(center,radius, _hit);
}

const bool Sphere::isCollision(const Shape * _shape, Hit* _hit) const
{
	return _shape->isCollision(this,_hit);
}

void Sphere::draw(const Renderer& renderer, const GScolor& color)
{
	renderer.getDraw3D().drawSphere(&center,radius,color);
}

const bool Sphere::isInsideCameraView(const Camera & _camera) const
{
	return _camera.isFrustumCulling(center,radius);
}

const float Sphere::cameraDistance(const Camera & _camera) const
{
	return _camera.nearDistance(center,radius);
}

const bool Sphere::isCollitionMap(const Map & _map, GSvector3 * _out_center) const
{
	return _map.isCollisionSphere(center,radius,_out_center);
}