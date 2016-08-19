#pragma once
#ifndef _COLLISIONMANAGER_H_
#define _COLLISIONMANAGER_H_
#include "../Include/EntityManager.h"
#include "CollisionObject.h"

#include <vector>
#include "Collision.h"
#include "CollisionMediator.h"
class CollisionManager:public CollisionMediator
{
public:
	CollisionManager();
	~CollisionManager();
	void add(CollisionObject* obj);
	void add(GameObject* parent, Shape* shape, const GSvector3& offset=GSvector3(0.0f,0.0f,0.0f));
	void initialize();
	void update(float deltaTime);
	void draw(const Renderer3D& renderer);

private:
	EntityManager<CollisionObject,std::vector> objects;
	Collision collision;
};
#endif