#pragma once
#include <gslib.h>
#include <string>
struct Transform
{
	GSvector3 m_scale;
	GSquaternion m_rotate;
	GSvector3 m_translate;
public:
	Transform();
	Transform(const GSvector3& _translate,const GSquaternion& _rotate = { 0.0f,0.0f,0.0f,1.0f }, const GSvector3& _scale = {1.0f,1.0f,1.0f});
	Transform(float _angle, const GSvector3& _axis,const GSvector3& _translate = { 0.0f,0.0f,0.0f }, const GSvector3& _scale = { 1.0f,1.0f,1.0f });
	//ロール,ヨー,ピッチ
	Transform(const GSvector3& _rotate, const GSvector3& _translate = { 0.0f,0.0f,0.0f }, const GSvector3& _scale = { 1.0f,1.0f,1.0f });
	Transform(const GSmatrix4& _mat);
	~Transform();
	void translate(const GSvector3& _velocity);
	void translate_front(float _velocity);
	void translate_left(float _velocity);
	void translate_up(float _velocity);
	void rotate(const GSquaternion& _q);
	void rotate(float _angle, const GSvector3& _axis);
	//ロール,ヨー,ピッチ
	void rotate(const GSvector3& _rotate);
	void rotateX(float _angle);
	void rotateY(float _angle);
	void rotateZ(float _angle);
	void scale(const GSvector3& _scale);

	const float getPitch()const;
	const float getYaw()const;
	const float getRoll()const;
	const GSvector3 getPosition()const;

	const GSvector3 front()const;
	const GSvector3 left()const;
	const GSvector3 up()const;
	const GSmatrix4 matrix()const;

	Transform lerp(Transform& _target, float _t);

	const std::string to_string()const;

	const Transform parent_synthesis(const Transform& _parent)const;
};