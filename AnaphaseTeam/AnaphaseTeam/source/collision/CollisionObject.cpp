#include "../../header/collision/CollisionObject.h"

#include "../../header/actor/Actor.h"
#include "../../header/collision/CollisionTable.h"

CollisionObject::CollisionObject(Actor * parent, Shape_Ptr shape, CollisionType _type, const CollisionFunction& _collision)
	:parent(parent), shape(shape),m_type(_type),m_collision(_collision)
{
}

CollisionObject::~CollisionObject()
{
}
const bool CollisionObject::isCollision(const CollisionObject * other, const CollisionTable& _table) const
{
	if (parent->isSameActor(other->parent))
	{
		return false;
	}
	if (!parent->isConfirmCollisionTable(_table, other->parent))
	{
		return false;
	}
	return shape->isCollision(other->shape.get());
}

void CollisionObject::collision(CollisionObject * other)
{
	if (m_collision == nullptr)return;
	m_collision(other->parent, other->m_type);
}

void CollisionObject::draw(const Renderer & renderer, const GScolor & _color)
{
	shape->draw(renderer, _color);
}
