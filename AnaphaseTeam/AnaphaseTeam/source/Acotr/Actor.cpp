#include "../../header/actor/Actor.h"
#include "../../header/camera/Camera.h"

#include"../../header/math/Calculate.h"
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
