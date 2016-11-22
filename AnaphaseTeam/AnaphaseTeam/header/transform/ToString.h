#pragma once
#include <GSvector2.h>
#include <GSvector3.h>
#include <GSvector4.h>
#include <GSquaternion.h>
#include <GSmatrix4.h>
#include <string>
class ToString
{
public:
	const std::string operator ()(float _value)const
	{
		return std::to_string(_value);
	}
	const std::string operator ()(const GSvector2& _vector)const
	{
		return "(" + (*this)(_vector.x) + "," + (*this)(_vector.y)+")";
	}
	const std::string operator ()(const GSvector3& _vector)const
	{
		return "(" + (*this)(_vector.x) + "," + (*this)(_vector.y) +  ","  + (*this)(_vector.z)+")";
	}
	const std::string operator ()(const GSvector4& _vector)const
	{
		return "(" + (*this)(_vector.x) +  ","  + (*this)(_vector.y)+ "," + (*this)(_vector.z)+  ","  + (*this)(_vector.w)+")";
	}
	//���Ɗp�x�ɕϊ� (axis,angle)
	const std::string operator ()(const GSquaternion& _quaternion)const
	{
		GSvector3 axis = _quaternion.getAxis();
		float angle = _quaternion.getAngle();
		return "(" + (*this)(axis.x) + "," + (*this)(axis.y)
			+ "," + (*this)(axis.z) + "," + (*this)(angle) + ")";
	}
	//�ʒu,���Ɗp�x,�g��ɕϊ�
	const std::string operator ()(const GSmatrix4& _mat)const
	{
		GSvector3 pos = _mat.getPosition();
		GSquaternion q = _mat.getQuaternion();
		GSvector3 scale = _mat.getScale();
		return "POSITION:" + (*this)(pos) +"ROTATE:" + (*this)(q) + "SCALE:" + (*this)(scale);
	}

};