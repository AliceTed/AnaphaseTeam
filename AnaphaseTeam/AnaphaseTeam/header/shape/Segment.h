#pragma once
#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "Shape.h"
/*���N���X*/
class Segment:public Shape
{
public:
	Segment(const GSvector3& _begin, const GSvector3& _vector);
	~Segment();
	//const bool isCollision(const Ray* _ray)const;
	const bool isCollision(const Sphere* _sphere)const;
	const bool isCollision(const Capsule* _capsule)const;
	const bool isCollision(const Segment* _segment)const;

	const bool isCollision(const Shape* _shape)const;
	void draw(const Renderer& renderer, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f));

	const bool isCollisionSphere(const GSvector3& _center,float _radius)const;
	const bool isCollisionCapsule(const Segment& _other, float _radius)const;
	
	//�I�_�擾
	const GSvector3 end()const;
	//�n�_�擾(Capsule�p)
	const GSvector3& begin()const;
	const GSvector3 vector()const;
private:
	GSvector3 m_begin;
	GSvector3 m_vector;
};


#endif