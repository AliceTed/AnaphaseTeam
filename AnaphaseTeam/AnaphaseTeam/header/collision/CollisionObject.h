#pragma once
#ifndef _COLLISIONOBJECT_H_
#define _COLLISIONOBJECT_H_
#include "../shape/Shape.h"
#include <memory>
class Actor;
class Renderer;
class CollisionTable;
typedef std::shared_ptr<Shape> Shape_Ptr;
class CollisionObject
{
public:
	CollisionObject(Actor* parent,Shape_Ptr shape);
	~CollisionObject();

	const bool isCollision(const CollisionObject* other,const CollisionTable& _table)const;
	void collision(CollisionObject* other);

	void draw(const Renderer& renderer,const GScolor& _color=GScolor(1,1,1,1));
private:
	Shape_Ptr shape;//基本形状
	Actor* parent;//親クラス
};
#endif