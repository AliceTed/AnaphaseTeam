#include "../../header/actor/Actor.h"
#include "../../header/camera/Camera.h"

#include"../../header/math/Calculate.h"
#include "../../header/map/Map.h"
#include "../../header/shape/Ray.h"
const float Actor::ALPHABLEND_FAR = 2.0f;

Actor::Actor(const Transform & _transform, MODEL_ID _modelID,const Sphere& _sphere)
	:m_transform(_transform), 
	m_isDead(false),
	m_Color(1.0f,1.0f,1.0f,1.0f),
	m_Sphere(_sphere),
	m_animator(_modelID)
{
}
Actor::Actor(const Transform & _transform, const ANIMATION_ID _anim_ID, const SKELETON_ID _skelton_ID, const Sphere & _sphere)
	:m_transform(_transform),
	m_isDead(false),
	m_Color(1.0f, 1.0f, 1.0f, 1.0f),
	m_Sphere(_sphere),
	m_animator(_anim_ID,_skelton_ID)
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
	//Œ»İ‚ÌˆÊ’u‚©‚ç‰º•ûŒü‚ÌRay‚ğì‚é
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
	//map‚É–„‚ß‚Ü‚ê‚Ä‚¢‚½‚çyÀ•W‚ğŒğ“_‚ÉˆÚ“®
	m_transform.setPositionY(intersect.y);
}
const float Actor::distanceActor(const Actor & _ohter) const
{
	return m_transform.getPosition().distance(_ohter.m_transform.getPosition());
}
const float Actor::distance(const GSvector3 & _position) const
{
	return m_transform.getPosition().distance(_position);
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
