#pragma once
#ifndef _BOXOBB_H_
#define _BOXOBB_H_
#include <gslib.h>
#include  "Shape.h"
#include <vector>
class Renderer3D;
/*
OBB
*/
struct OBB:public Shape
{
	OBB(GSvector3 pos, GSvector3 radius, GSvector3 rot);
	~OBB();

	void expand(const GSvector3& _radius);
	void translate(const GSvector3& _position);
	void transfer(const GSvector3& _position);
	void rotate(GSvector3 _rot);

	/*���܂藝�����Ă��Ȃ�*/
	const bool intersects(const OBB& other)const;
	void draw(const Renderer3D& renderer);
	const SHAPETYPE getType()const;

	const GSvector3 overVector(const GSvector3& position, const GSvector3& dir, const GSvector3& point, float L)const;
	const float point_distance(const GSvector3& point)const;
	const bool compareAxis(const OBB& other, const std::vector<GSvector3> axis, const GSvector3& distance)const;
	/*
	* OBB�̓��e������r
	*/
	const bool compareLengthOBB(const OBB& other,const GSvector3& vSep,const GSvector3& vDistance)const;
	// ���������X�V
	void rotToAxis();

	GSvector3 position;    // ���S���W
	GSvector3 radius; // ���a
	GSvector3 rot;    // ��]�p�x

	GSvector3 axisX;  // ������X
	GSvector3 axisY;  // ������Y
	GSvector3 axisZ;  // ������Z
};

#endif