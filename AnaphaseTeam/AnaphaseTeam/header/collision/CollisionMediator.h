#pragma once
#ifndef _COLLISIONMEDIATOR_H_
#define _COLLISIONMEDIATOR_H_
#include "CollisionObject.h"
class CollisionMediator
{
public:
	virtual ~CollisionMediator() {}
	virtual void add(CollisionObject* obj)=0;
	virtual void add(GameObject* parent, Shape* shape, const GSvector3& offset = GSvector3(0.0f, 0.0f, 0.0f)) = 0;
};

#endif