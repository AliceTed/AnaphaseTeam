#include "../../header/actor/Actor.h"
#include "../../header/camera/Camera.h"

#include"../../header/math/Calculate.h"
#include "../../header/map/Map.h"
#include "../../header/shape/Ray.h"
#include "../../header/collision/CollisionTable.h"
const float Actor::ALPHABLEND_FAR = 2.0f;

Actor::Actor(const Transform & _transform, MODEL_ID _modelID,const Sphere& _sphere, Actor_Tag _tag)
	:m_transform(_transform), 
	m_isDead(false),
	m_Color(1.0f,1.0f,1.0f,1.0f),
	m_animator(_modelID),
	m_Sphere(_sphere),
	m_Tag(_tag)
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
	//���݂̈ʒu���牺������Ray�����
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
	//map�ɖ��ߍ��܂�Ă�����y���W����_�Ɉړ�
	m_transform.setPositionY(intersect.y);
}
void Actor::collision(const Actor * _other)
{
}
void Actor::createCollision(CollisionMediator * _mediator)
{
}
const GSvector3 Actor::vectorToFront(const GSvector3 & _vector) const
{
	return _vector.cross(m_transform.front());
}
const float Actor::distanceActor(const Actor & _other) const
{
	return m_transform.getPosition().distance(_other.m_transform.getPosition());
}
const float Actor::distance(const GSvector3 & _position) const
{
	return m_transform.getPosition().distance(_position);
}
const bool Actor::isSameActor(const Actor * _other) const
{
	return this==_other;
}
const bool Actor::isSameTag(Actor_Tag _tag) const
{
	return m_Tag==_tag;
}
const bool Actor::isConfirmCollisionTable(const CollisionTable & _table, const Actor * _other) const
{
	return _table.isConfirmTag(m_Tag,_other->m_Tag);
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