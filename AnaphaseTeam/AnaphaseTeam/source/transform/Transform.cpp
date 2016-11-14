#include "../../header/transform/Transform.h"
#include "../../header/transform/Quaternion_Utility.h"
#include "../../header/transform/ToString.h"
Transform::Transform()
	:m_scale(1.0f, 1.0f, 1.0f),
	m_rotate(0.0f, { 0.0f,0.0f,0.0f }),
	m_translate(0.0f, 0.0f, 0.0f)
{

}

Transform::Transform(const GSvector3 & _translate, const GSquaternion & _rotate, const GSvector3 & _scale)
	:m_scale(_scale),
	m_rotate(_rotate),
	m_translate(_translate)
{
}

Transform::Transform(float _angle, const GSvector3 & _axis, const GSvector3 & _translate, const GSvector3 & _scale)
	:m_scale(_scale),
	m_rotate(_angle,_axis),
	m_translate(_translate)
{
}
Transform::Transform(const GSvector3 & _rotate, const GSvector3 & _translate, const GSvector3 & _scale)
	:m_scale(_scale),
	m_rotate(),
	m_translate(_translate)
{
	m_rotate.setRotateYawPitchRoll(_rotate.y, _rotate.z, _rotate.x);
}
Transform::Transform(const GSmatrix4 & _mat)
	: m_scale(_mat.getScale()),
	m_rotate(_mat.getQuaternion()),
	m_translate(_mat.getPosition())
{
}
Transform::~Transform()
{
}

void Transform::translate(const GSvector3 & _velocity)
{
	m_translate += _velocity;
}

void Transform::translate_front(float _velocity)
{
	m_translate += front()*_velocity;
}

void Transform::translate_left(float _velocity)
{
	m_translate += left()*_velocity;
}

void Transform::translate_up(float _velocity)
{
	m_translate += up()*_velocity;
}

void Transform::rotate(const GSquaternion & _q)
{
	m_rotate *= _q;
}

void Transform::rotate(float _angle, const GSvector3 & _axis)
{
	rotate(GSquaternion(_angle, _axis));
}

void Transform::rotate(const GSvector3 & _rotate)
{
	GSquaternion q;
	q.setRotateYawPitchRoll(_rotate.y, _rotate.z, _rotate.x);
	rotate(q);
}

void Transform::rotateX(float _angle)
{
	rotate(_angle, GSvector3(1.0f, 0.0f, 0.0f));
}

void Transform::rotateY(float _angle)
{
	rotate(_angle, GSvector3(0.0f, 1.0f, 0.0f));
}

void Transform::rotateZ(float _angle)
{
	rotate(_angle, GSvector3(0.0f, 0.0f, 1.0f));
}

void Transform::scale(const GSvector3 & _scale)
{
	m_scale *= _scale;
}

const float Transform::getPitch() const
{
	return m_rotate.getPitch();
}

const float Transform::getYaw() const
{
	return m_rotate.getYaw();
}

const float Transform::getRoll() const
{
	return m_rotate.getRoll();
}

const GSvector3 Transform::front() const
{
	Quaternion_Utility util;
	GSvector3 f = util.rotation(m_rotate, GSvector3(0.0f, 0.0f, 1.0f));
	return f.normalize();
}

const GSvector3 Transform::left() const
{
	Quaternion_Utility util;
	GSvector3 r = util.rotation(m_rotate, GSvector3(1.0f, 0.0f, 0.0f));
	return r.normalize();
}

const GSvector3 Transform::up() const
{
	Quaternion_Utility util;
	GSvector3 r = util.rotation(m_rotate, GSvector3(0.0f,1.0f, 0.0f));
	return r.normalize();
}

const GSmatrix4 Transform::matrix() const
{
	GSmatrix4 mat = GS_MATRIX4_IDENTITY;
	mat.scale(m_scale);
	mat.rotate(m_rotate);
	mat.translate(m_translate);
	return mat;
}

Transform Transform::lerp(Transform & _target, float _t)
{
	Transform res;
	res.m_scale = m_scale.lerp(_target.m_scale, _t);
	res.m_rotate=m_rotate.lerp(_target.m_rotate, _t);
	res.m_translate= m_translate.lerp(_target.m_translate, _t);
	return res;
}

const std::string Transform::to_string()const
{
	ToString to;
	return "POSITION:" + to(m_translate) + "ROTATE:" + to(m_rotate) + "SCALE:" + to(m_scale);
}

const Transform Transform::parent_synthesis(const Transform & _parent) const
{
	return Transform(matrix()*_parent.matrix());
}

