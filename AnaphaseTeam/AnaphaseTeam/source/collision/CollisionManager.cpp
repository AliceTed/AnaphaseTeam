//#include "CollisionManager.h"
//
//CollisionManager::CollisionManager()
//	:objects(),collision()
//{
//}
//
//CollisionManager::~CollisionManager()
//{
//}
//
//void CollisionManager::add(CollisionObject * obj)
//{
//	objects.add(obj);
//}
//
//void CollisionManager::add(GameObject * parent, Shape * shape, const GSvector3 & offset)
//{
//	objects.add(new CollisionObject(parent,shape,offset));
//}
//
//void CollisionManager::initialize()
//{
//	objects.clear();
//}
//
//void CollisionManager::update(float deltaTime)
//{
//	objects.acceptPair([&](CollisionObject* obj1, CollisionObject* obj2)
//	{
//		if (!obj1->isCollision(&collision, obj2))
//		{
//			return;
//		}
//		obj1->collision(obj2);
//		obj2->collision(obj1);
//	});
//	objects.clear();
//}
//
//void CollisionManager::draw(const Renderer3D& renderer)
//{
//	/*objects.accept([&](CollisionObject* obj) {obj->draw(renderer);});
//	objects.clear();*/
//}
