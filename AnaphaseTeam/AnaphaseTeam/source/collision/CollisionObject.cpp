//#include "CollisionObject.h"
//
//#include "CollisionManager.h"
//#include "GameObject.h"
//#include "Collision.h"
//CollisionObject::CollisionObject(GameObject* parent,Shape* shape, const GSvector3& offset)
//	:parent(parent),shape(std::shared_ptr<Shape>(shape)), offset(offset)
//{
//	shape->translate(offset);
//}
//
//CollisionObject::~CollisionObject()
//{
//}
//const bool CollisionObject::isCollision(const Collision * collision, const CollisionObject * other) const
//{
//	if (parent->isSameObject(other->parent))
//	{
//		return false;
//	}
//	if (!parent->isConfirmCollisionTable(collision,other->parent))
//	{
//		return false;
//	}
//
//	return collision->isCollision(*shape.get(), *other->shape.get());
//}
//
//void CollisionObject::collision(CollisionObject * other)
//{
//	parent->collision(other->parent);
//}
//
//void CollisionObject::draw(const Renderer3D & renderer)
//{
//	shape->draw(renderer);
//}
