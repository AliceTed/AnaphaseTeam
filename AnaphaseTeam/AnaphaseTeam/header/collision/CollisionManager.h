#pragma once
#ifndef _COLLISIONMANAGER_H_
#define _COLLISIONMANAGER_H_
#include "../entity/EntityManager.h"
#include "CollisionObject.h"

#include "Collision.h"
#include "CollisionMediator.h"
#include <memory>
typedef std::shared_ptr<CollisionObject> Obj_Ptr;
class CollisionManager:public CollisionMediator
{
public:
	CollisionManager();
	~CollisionManager();
	void add(Obj_Ptr _obj);

	void initialize();
	void update(float deltaTime);
	void draw(const Renderer& renderer);

	void collision(Obj_Ptr _obj1, Obj_Ptr _obj2);
private:
	Entity::EntityManager<Obj_Ptr> m_Container;
};
#endif