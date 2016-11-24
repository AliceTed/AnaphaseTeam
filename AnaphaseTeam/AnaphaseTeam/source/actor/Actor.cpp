#include "../../header/actor/Actor.h"
#include "../../header/camera/Camera.h"

#include"../../header/math/Calculate.h"
#include "../../header/map/Map.h"
#include "../../header/shape/Ray.h"
#include "../../header/math/Calculate.h"
const float Actor::ALPHABLEND_FAR = 2.0f;
const float Actor::GRAVITY = -0.1f;

Actor::Actor(const Transform & _transform, MODEL_ID _modelID,const Sphere& _sphere,Actor_Tag _tag)
	:m_transform(_transform), 
	m_isDead(false),
	m_Color(1.0f,1.0f,1.0f,1.0f),
	m_animatorOne(_modelID),
	m_Sphere(_sphere),
	m_Tag(_tag),
	m_collision(this)
{
}

Actor::~Actor()
{
	m_collision.initialize();
}

void Actor::initialize()
{
	m_collision.initialize();
	m_Color=GScolor(1.0f, 1.0f, 1.0f, 1.0f);
	m_isDead = false;
}

void Actor::finish()
{
}
void Actor::collisionGround(const Map& _map)
{
	GSvector3 intersect;
	//åªç›ÇÃà íuÇ©ÇÁâ∫ï˚å¸ÇÃRayÇçÏÇÈ
	GSvector3 position = m_transform.m_translate;
	Ray ray(position);
	if (!ray.isCollitionMap(_map, &intersect))
	{
		return;
	}
	if (position.y > intersect.y)
	{
		//m_transform.translateY(GRAVITY);
		m_transform.translate_up(GRAVITY);
		return;
	}
	inGround();
	//mapÇ…ñÑÇﬂçûÇ‹ÇÍÇƒÇ¢ÇΩÇÁyç¿ïWÇåì_Ç…à⁄ìÆ
	m_transform.m_translate.y = intersect.y;
}
void Actor::collision(Actor & _other)
{
	m_collision.collision(_other.m_collision);
}

void Actor::inGround()
{
}
const float Actor::distanceActor(const Actor & _other) const
{
	return m_transform.m_translate.distance(_other.m_transform.m_translate);
}
const float Actor::distance(const GSvector3 & _position) const
{
	return m_transform.m_translate.distance(_position);
}
const GSquaternion Actor::targetDirection(const Actor & _target) const
{
	GSvector3 vector = _target.m_transform.m_translate - m_transform.m_translate;
	Math::ATan atan;
	float radian = atan(vector.z, vector.x);
	return GSquaternion(radian, { 0,1,0 });
}
const bool Actor::isSameActor(const Actor * _other) const
{
	return this==_other;
}
const bool Actor::isSameTag(Actor_Tag _tag) const
{
	return m_Tag==_tag;
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
	m_Sphere.transfer(m_transform.m_translate +_offset);
}

void Actor::sphereDraw(const Renderer & _renderer)
{
	m_Sphere.draw(_renderer, m_Color);
}
