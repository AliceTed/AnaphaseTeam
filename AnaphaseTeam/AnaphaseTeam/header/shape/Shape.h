#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <gslib.h>
class IRenderer;

//class Ray;
class Sphere;
class Capsule;
class Segment;
class Shape
{
public:
	virtual ~Shape() {}
	//add
	virtual void translate(const GSvector3& _position) = 0;
	//���
	virtual void transfer(const GSvector3& _position) = 0;

	//virtual const bool isCollision(const Ray* _ray)const = 0;
	virtual const bool isCollision(const Sphere* _sphere, GSvector3* _out)const = 0;
	virtual const bool isCollision(const Capsule* _capsule, GSvector3* _out)const = 0;
	virtual const bool isCollision(const Segment* _segment, GSvector3* _out)const = 0;

	virtual const bool isCollision(const Shape* _shape, GSvector3* _out)const = 0;

	virtual void draw(IRenderer * _renderer, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f)) = 0;
};

#endif