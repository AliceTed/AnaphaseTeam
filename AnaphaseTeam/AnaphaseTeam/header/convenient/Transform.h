#pragma once
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include <gslib.h>
class Transform
{
public:
	Transform();
	//rotate(pitch,yaw,roll)
	Transform(
		const GSvector3& _position,
		const GSvector3& _rotate = GSvector3(0.0f, 0.0f, 0.0f),
		const GSvector3 & _scale = GSvector3(1.0f, 1.0f, 1.0f)
		);
	Transform(const GSmatrix4& _mat);
	~Transform();

	void setPosition(const GSvector3& _position);
	
	void setPositionX(float _x);
	void setPositionY(float _y);
	void setPositionZ(float _z);

	void translate(const GSvector3& _position);
	void translateX(float _x);
	void translateY(float _y);
	void translateZ(float _z);

	void setRotate(const GSvector3& rotate);
	void setRotate(float pitch,float yaw,float roll);
	//x
	void setPitch(float _angle);
	//y
	void setYaw(float _angle);
	//z
	void setRoll(float _angle);

	void rotation(const GSvector3 & rotate);
	void rotationX(float _angle);
	void rotationY(float _angle);
	void rotationZ(float _angle);

	void setScale(const GSvector3& _scale);
	void scaling(const GSvector3& _scale);

	const GSvector3& getPosition()const;
	const float getRoll()const;
	const float getPitch()const;
	const float getYaw()const;
	const GSvector3& getRotate()const;
	const GSvector3& getScale()const;

	const GSmatrix4 getMatrix4()const;

	const GSvector3 front()const;
	const GSvector3 left()const;
	const GSvector3 up()const;
	//êeÇÃmatrix4Ç∆çáê¨
	const GSmatrix4 parentSynthesis(const Transform& parent);
private:
	GSvector3 m_Rotate;// pitch,yaw,roll
	GSvector3 m_Position;
	GSvector3 m_Scale;
};
#endif