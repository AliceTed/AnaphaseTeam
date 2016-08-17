#include "../../header/actor/Actor.h"
#include "../../header/camera/Camera.h"

#include"../../header/math/Calculate.h"
#include "../../header/map/Map.h"
#include "../../header/shape/Ray.h"
const float Actor::ALPHABLEND_FAR = 2.0f;

Actor::Actor(const Transform & _transform, const Sphere& _sphere)
	:m_transform(_transform), 
	m_isDead(false),
	m_Color(1.0f,1.0f,1.0f,1.0f),
	m_Sphere(_sphere)
{
}
void Actor::initialize()
{
	m_Color=GScolor(1.0f, 1.0f, 1.0f, 1.0f);
	m_isDead = false;
}

void Actor::finish()
{
}

void Actor::collisionGround(const Map& _map)
{
	GSvector3 intersect;
	GSvector3 position = m_transform.getPosition();
	Ray ray(position);
	if (!ray.isCollitionMap(_map, &intersect))
	{
		return;
	}

	if (position.y >= intersect.y)
	{
		return;
	}
	m_transform.setPositionY(intersect.y);
}

void Actor::cameraChases(Camera & _camera)
{
	_camera.lookAt(m_transform.getPosition(), m_transform.getYaw());
}

const float Actor::cameraDistance(const Camera & _camera) const
{
	return _camera.distance(m_transform.getPosition());
}

const bool Actor::isDead() const
{
	return m_isDead;
}

void Actor::alphaBlend(const Camera & _camera)
{
	 float distance =m_Sphere.cameraDistance(_camera);
	 Math::Clamp clamp;
	 m_Color.a=clamp(distance / ALPHABLEND_FAR,0.0f,1.0f);
}

const bool Actor::isInsideView(const Camera & _camera) const
{
	return m_Sphere.isInsideCameraView(_camera);
}

void Actor::sphereChases(const GSvector3 & _offset)
{
	m_Sphere.transfer(m_transform.getPosition() +_offset);
}

void Actor::sphereDraw(const Renderer & _renderer)
{
	m_Sphere.draw(_renderer, m_Color);
}
