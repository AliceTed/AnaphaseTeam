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
	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);
	//const bool isCollision(const Ray* _ray)const;
	const bool isCollision(const Sphere* _sphere, Hit* _hit)const;
	const bool isCollision(const Capsule* _capsule, Hit* _hit)const;
	const bool isCollision(const Segment* _segment, Hit* _hit)const;

	const bool isCollision(const Shape* _shape,Hit* _hit)const;

	void draw(const Renderer& renderer, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f));

	const bool isCollisionSphere(const GSvector3& _center, float radius, Hit* _hit)const;
private:
	Segment m_Segment;
	float m_Radius;
};
#endif

