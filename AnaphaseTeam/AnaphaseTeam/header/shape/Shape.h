#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <gslib.h>
class Renderer;

//class Ray;
class Sphere;
class Capsule;
class Segment;
class Shape
{
public:
	virtual ~Shape() {}
	//add
	virtual void translate(const GSvector3& _position)=0;
	//‘ã“ü
	virtual void transfer(const GSvector3& _position)=0;

	//virtual const bool isCollision(const Ray* _ray)const = 0;
	virtual const bool isCollision(const Sphere* _sphere)const = 0;
	virtual const bool isCollision(const Capsule* _capsule)const = 0;
	virtual const bool isCollision(const Segment* _segment)const = 0;

	virtual const bool isCollision(const Shape* _shape)const = 0;

	virtual void draw(const Renderer& _renderer, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f)) = 0;
};

#endif