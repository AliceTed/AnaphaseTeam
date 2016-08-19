#include "../../header/collision/CollisionObject.h"

#include "../../header/actor/Actor.h"


CollisionObject::CollisionObject(Actor * _parent, Shape_Ptr _shape)
	:parent(_parent),shape(_shape)
{
}

CollisionObject::~CollisionObject()
{
}
const bool CollisionObject::isCollision(const CollisionObject * other) const
{
	if (parent->isSameActor(other->parent))
	{
		return false;
	}
	//if (!parent->isConfirmCollisionTable(collision, other->parent))
	//{
	//	return false;
	//}
	return shape->isCollision(other->shape.get());
}

void CollisionObject::collision(CollisionObject * other)
{
	parent->collision(other->parent);
}

void CollisionObject::draw(const Renderer & renderer, const GScolor & _color)
{
	shape->draw(renderer, _color);
}
