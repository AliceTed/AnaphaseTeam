#pragma once
#ifndef _COLLISIONMEDIATOR_H_
#define _COLLISIONMEDIATOR_H_

#include "CollisionObject.h"
typedef std::shared_ptr<CollisionObject> Obj_Ptr;
class CollisionMediator
{
public:
	virtual ~CollisionMediator() {}
	virtual void add(Obj_Ptr _obj)= 0;
};

#endif