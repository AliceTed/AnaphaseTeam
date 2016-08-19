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

	/*‚ ‚Ü‚è—‰ğ‚µ‚Ä‚¢‚È‚¢*/
	const bool intersects(const OBB& other)const;
	void draw(const Renderer3D& renderer);
	const SHAPETYPE getType()const;

	const GSvector3 overVector(const GSvector3& position, const GSvector3& dir, const GSvector3& point, float L)const;
	const float point_distance(const GSvector3& point)const;
	const bool compareAxis(const OBB& other, const std::vector<GSvector3> axis, const GSvector3& distance)const;
	/*
	* OBB‚Ì“Š‰e‹——£”äŠr
	*/
	const bool compareLengthOBB(const OBB& other,const GSvector3& vSep,const GSvector3& vDistance)const;
	// •ª—£²‚ğXV
	void rotToAxis();

	GSvector3 position;    // ’†SÀ•W
	GSvector3 radius; // ”¼Œa
	GSvector3 rot;    // ‰ñ“]Šp“x

	GSvector3 axisX;  // •ª—£²X
	GSvector3 axisY;  // •ª—£²Y
	GSvector3 axisZ;  // •ª—£²Z
};

#endif