#pragma once
#ifndef _COLLISIONOBJECT_H_
#define _COLLISIONOBJECT_H_
#include "Shape.h"
#include <memory>
class GameObject;
class Collision;
class CollisionObject
{
public:
	CollisionObject(GameObject* parent,Shape* shape,const GSvector3& offset=GSvector3(0,0,0));
	~CollisionObject();

	const bool isCollision(const Collision* collision,const CollisionObject* other)const;
	void collision(CollisionObject* other);

	void draw(const Renderer3D& renderer);
private:
	GSvector3 offset;//基本形状に対してのoffset
	std::shared_ptr<Shape> shape;//基本形状
	GameObject* parent;//親クラス
};
#endif