#include "../../header/shape/Sphere.h"

#include "../../header/renderer/IRenderer.h"
#include "../../header/camera/Camera.h"
#include "../../header/map/Map.h"

//#include "../../header/shape/Ray.h"
#include "../../header/shape/Capsule.h"
#include "../../header/shape/Segment.h"
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

const bool Sphere::isCollision(const Sphere * _sphere, GSvector3* _out) const
{
	//intersect
	GSvector3 v = _sphere->center - center;
	v.normalize();
	*_out = center + (v*radius);
	return  center.distance(_sphere->center) <radius + _sphere->radius;
}

const bool Sphere::isCollision(const Capsule * _capsule, GSvector3* _out) const
{
	return _capsule->isCollisionSphere(center, radius, _out);
}

const bool Sphere::isCollision(const Segment * _segment, GSvector3* _out) const
{
	return _segment->isCollisionSphere(center, radius, _out);
}

const bool Sphere::isCollision(const Shape * _shape, GSvector3* _out) const
{
	return _shape->isCollision(this, _out);
}

void Sphere::draw(IRenderer * renderer, const GScolor& color)
{
	//renderer.getDraw3D().drawSphere(&center, radius, color);
	glPushMatrix();
	glTranslatef(center.x, center.y, center.z);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();
}

const bool Sphere::isInsideCameraView(const Camera & _camera) const
{
	return _camera.isFrustumCulling(center, radius);
}

const float Sphere::cameraDistance(const Camera & _camera) const
{
	return _camera.nearDistance(center, radius);
}

const bool Sphere::isCollitionMap(const Map & _map, GSvector3 * _out_center) const
{
	return _map.isCollisionSphere(center, radius, _out_center);
}