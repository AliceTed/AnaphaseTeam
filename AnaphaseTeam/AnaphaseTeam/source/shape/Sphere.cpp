#include "../../header/shape/Sphere.h"

#include "../../header/renderer/Renderer.h"
#include "../../header/camera/Camera.h"
#include "../../header/map/Map.h"
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

const bool Sphere::intersects(const Sphere & other) const
{
	return center.distance(other.center) <radius + other.radius;
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

//const SHAPETYPE Sphere::getType() const
//{
//	return SHAPETYPE::SHPERE;
//}
