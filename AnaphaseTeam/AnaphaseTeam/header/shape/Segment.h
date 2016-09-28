#pragma once
#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "Shape.h"
/*線クラス*/
class Segment:public Shape
{
public:
	Segment(const GSvector3& _begin, const GSvector3& _vector);
	~Segment();

	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);
	//const bool isCollision(const Ray* _ray)const;
	const bool isCollision(const Sphere* _sphere)const;
	const bool isCollision(const Capsule* _capsule)const;
	const bool isCollision(const Segment* _segment)const;

	const bool isCollision(const Shape* _shape)const;
	void draw(const Renderer& renderer, const GScolor& color = GScolor(1.0f, 1.0f, 1.0f, 1.0f));

	const bool isCollisionSphere(const GSvector3& _center,float _radius)const;
	const bool isCollisionCapsule(const Segment& _other, float _radius)const;
	
	//終点取得
	const GSvector3 end()const;
	//始点取得(Capsule用)
	const GSvector3& begin()const;
	const GSvector3& vector()const;
	//点が線分上にあるか？
	const bool isONPoint(const GSvector3& _point)const;

private:
	GSvector3 m_begin;
	GSvector3 m_vector;
};


#endif