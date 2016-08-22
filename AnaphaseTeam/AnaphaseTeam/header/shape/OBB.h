#pragma once
#ifndef _BOXOBB_H_
#define _BOXOBB_H_
#include <gslib.h>
#include  "Shape.h"
#include "../array/Array.h"
class Renderer;
/*
OBB
*/
class OBB:public Shape
{
public:
	OBB(const GSvector3 &_position,const GSvector3& _radius, const GSvector3& _rotate);
	~OBB();
	const bool isCollision(const Sphere* _sphere)const;
	//–¢À‘•
	const bool isCollision(const Capsule* _capsule)const;
	//–¢À‘•
	const bool isCollision(const Segment* _segment)const;
	const bool isCollision(const OBB* _obb)const;

	const bool isCollision(const Shape* _shape)const;
	void draw(const Renderer & renderer, const GScolor& color=GScolor(1,1,1,1));

	const bool isCollisionSphere(const GSvector3& _center, float _radius)const;
	const bool isCollisionSegment()const;
	const bool TestSegmentOBB(const Segment *_segment)const;
	
	void move(const GSvector3& move)
	{
		m_position += move;
	}
	void rot(const GSvector3& _rot)
	{
		m_rotate += _rot;
		rotateToAxis();
	}
private:
	// Še²‚É‚Â‚¢‚Ä‚Í‚İo‚½•”•ª‚ÌƒxƒNƒgƒ‹‚ğZo
	const GSvector3 axisProtrudedVector(const GSvector3& _axis,float radius,const GSvector3& _point)const;

	//“_‚Æ‚ÌÅ’Z‹——£
 	const float distance_point(const GSvector3 &_point)const;

	//Axis‚Ì”äŠr
	const bool axisCompare(const OBB* _other, const GSvector3 & _distance)const;
	//©g‚ÌAxis‚Æ”äŠr
	const bool selfAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	//‘Šè‚ÌAxis‚Æ”äŠr
	const bool otherAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	// •ª—£²“¯m‚ÌŠOÏ‚ğ”äŠr
	const bool crossAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	// ‰ñ“]Šp“x‚©‚ç•ª—£²‚ğ‹‚ß‚é(‰ñ“]‚ÆƒRƒ“ƒXƒgƒ‰ƒNƒ^‚Å‹‚ß‚é)
	void rotateToAxis();

	//OBB‚Ì“Š‰e‹——£”äŠr
	const bool compareLengthOBB(const OBB *_other, const GSvector3 vSep, const GSvector3 vDistance)const;
	//•ª—£²ã‚ÅÅ‚à‰“‚¢’¸“_‚Ü‚Å‚Ì‹——£
	const float farthestDistance(const GSvector3& _vSeq)const;

private:
	GSvector3 m_radius;//”¼Œa
	GSvector3 m_position;//’†SˆÊ’u
	GSvector3 m_rotate;    // ‰ñ“]Šp“x

	GSvector3 m_axisX;  // •ª—£²X
	GSvector3 m_axisY;  // •ª—£²Y
	GSvector3 m_axisZ;  // •ª—£²Z
};
#endif

