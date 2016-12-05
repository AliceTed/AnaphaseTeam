#pragma once
#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "Shape.h"
/*���N���X*/
class Segment :public Shape
{
public:
	Segment(const GSvector3& _begin, const GSvector3& _vector);
	~Segment();

	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);
	//const bool isCollision(const Ray* _ray)const;
	const bool isCollision(const Sphere* _sphere, GSvector3* _out)const;
	const bool isCollision(const Capsule* _capsule, GSvector3* _out)const;
	const bool isCollision(const Segment* _segment, GSvector3* _out)const;

	const bool isCollision(const Shape* _shape, GSvector3* _out)const;
	void draw(IRenderer * renderer, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f));

	const bool isCollisionSphere(const GSvector3& _center, float _radius, GSvector3* _out)const;
	const bool isCollisionCapsule(const Segment& _other, float _radius, GSvector3* _out)const;

	//�I�_�擾
	const GSvector3 end()const;
	//�n�_�擾(Capsule�p)
	const GSvector3& begin()const;
	const GSvector3& vector()const;
	//�_��������ɂ��邩�H
	const bool isONPoint(const GSvector3& _point)const;

private:
	GSvector3 m_begin;
	GSvector3 m_vector;
};


#endif