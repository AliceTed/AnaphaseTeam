#pragma once
#ifndef _BOXOBB_H_
#define _BOXOBB_H_
#include <gslib.h>
#include  "Shape.h"

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
	const bool isCollision(const Capsule* _capsule)const;
	const bool isCollision(const Segment* _segment)const;
	const bool isCollision(const OBB* _obb)const;

	const bool isCollision(const Shape* _shape)const;
	void draw(const Renderer & renderer, const GScolor& color=GScolor(1,1,1,1));

	const bool isCollisionSphere(const GSvector3& _center, float _radius)const;
	
	//判定が緩いけど取りあえず実装(+中身がリファクタ対象)
	const bool isCollisionSegment(const GSvector3& _begin, const GSvector3& _vector)const;
	const bool isCollisionCapsule(const GSvector3& _position, const GSvector3 &_vector, float _radius)const;
private:
	// 各軸についてはみ出た部分のベクトルを算出
	const GSvector3 axisProtrudedVector(const GSvector3& _axis,float radius,const GSvector3& _point)const;

	//点との最短距離
 	const float distance_point(const GSvector3 &_point)const;

	//Axisの比較
	const bool axisCompare(const OBB* _other, const GSvector3 & _distance)const;
	//自身のAxisと比較
	const bool selfAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	//相手のAxisと比較
	const bool otherAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	// 分離軸同士の外積を比較
	const bool crossAxisCompare(const OBB* _other, const GSvector3 & _distance)const;
	// 回転角度から分離軸を求める(回転時とコンストラクタで求める)
	void rotateToAxis();

	//OBBの投影距離比較
	const bool compareLengthOBB(const OBB *_other, const GSvector3 vSep, const GSvector3 vDistance)const;
	//分離軸上で最も遠い頂点までの距離
	const float farthestDistance(const GSvector3& _vSeq)const;


	//slabと線分が平行かどうかを判定し交差するか確認
	const bool parallel_Slab_Segment(float _radius, float _dir, float _pos)const;
	//各スラブで線分と交差するか
	const bool each_Slab_Segment(const GSvector3& _radius,const GSvector3& _dir, const GSvector3& _pos, const GSvector3& _axis)const;
private:
	GSvector3 m_radius;//半径
	GSvector3 m_position;//中心位置
	GSvector3 m_rotate;    // 回転角度

	GSvector3 m_axisX;  // 分離軸X
	GSvector3 m_axisY;  // 分離軸Y
	GSvector3 m_axisZ;  // 分離軸Z
};
#endif

