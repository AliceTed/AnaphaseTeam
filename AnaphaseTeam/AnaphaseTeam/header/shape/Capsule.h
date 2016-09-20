#pragma once
#ifndef _CAPSULE_H_
#define _CAPSULE_H_
#include <gslib.h>
#include "Shape.h"
#include "Segment.h"
class Capsule:public Shape
{
public:
	Capsule(const Segment& _segment, float radius);
	~Capsule();
	//const bool isCollision(const Ray* _ray)const;
	const bool isCollision(const Sphere* _sphere)const;
	const bool isCollision(const Capsule* _capsule)const;
	const bool isCollision(const Segment* _segment)const;
	const bool isCollision(const OBB* _obb)const;
	const bool isCollision(const AABB* _aabb)const;

	const bool isCollision(const Shape* _shape)const;

	void draw(const Renderer& renderer, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f));

	const bool isCollisionSphere(const GSvector3& _center, float radius)const;
private:
	Segment m_Segment;
	float m_Radius;
};
#endif
