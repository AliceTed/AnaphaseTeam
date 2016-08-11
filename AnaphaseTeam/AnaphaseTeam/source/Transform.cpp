#include "../header/Transform.h"
Transform::Transform()
	:m_Position(0.0f, 0.0f, 0.0f),
	m_Scale(1.0f,1.0f,1.0f),
	m_Rotate(0.0f,0.0f,0.0f)
{
}

Transform::Transform(const GSvector3 & _position, const GSvector3& _rotate, const GSvector3 & _scale)
	:m_Position(_position), m_Rotate(_rotate), m_Scale(_scale)
{
}

Transform::Transform(const GSmatrix4 & _mat)
	: m_Position(_mat.getPosition()),
	m_Rotate(_mat.getPitch(), _mat.getYaw(), _mat.getRoll()),
	m_Scale(_mat.getScale())
{
}

Transform::~Transform()
{
}
void Transform::setPosition(const GSvector3 & _position)
{
	m_Position = _position;
}

void Transform::translate(const GSvector3 & _position)
{
	m_Position += _position;
}
void Transform::setPositionX(float _x)
{
	m_Position.x = _x;
}

void Transform::setPositionY(float _y)
{
	m_Position.y = _y;
}

void Transform::setPositionZ(float _z)
{
	m_Position.z = _z;
}
void Transform::translateX(float _x)
{
	m_Position.x += _x;
}
void Transform::translateY(float _y)
{
	m_Position.y += _y;
}

void Transform::translateZ(float _z)
{
	m_Position.z += _z;
}

void Transform::setRotate(const GSvector3 & _rotate)
{
	m_Rotate = _rotate;
}

void Transform::setRotate(float pitch, float yaw, float roll)
{
	m_Rotate = GSvector3(pitch, yaw, roll);
}

void Transform::setPitch(float _angle)
{
	m_Rotate.x = _angle;
}

void Transform::setYaw(float _angle)
{
	m_Rotate. y= _angle;
}

void Transform::setRoll(float _angle)
{
	m_Rotate.z = _angle;
}

void Transform::rotation(const GSvector3 & _rotate)
{
	m_Rotate += _rotate;
}

void Transform::rotationX(float _angle)
{
	m_Rotate.x += _angle;
}

void Transform::rotationY(float _angle)
{
	m_Rotate.y += _angle;
}

void Transform::rotationZ(float _angle)
{
	m_Rotate.z += _angle;
}

void Transform::setScale(const GSvector3 & _scale)
{
	m_Scale = _scale;
}

void Transform::scaling(const GSvector3 & _scale)
{
	m_Scale += _scale;
}
const GSvector3& Transform::getPosition() const
{
	return m_Position;
}
const float Transform::getRoll() const
{
	return  m_Rotate.z;
}
const float Transform::getPitch() const
{
	return m_Rotate.x;
}
const float Transform::getYaw() const
{
	return m_Rotate.y;
}
const GSvector3 & Transform::getRotate() const
{
	return m_Rotate;
}
const GSvector3& Transform::getScale() const
{
	return m_Scale;
}
const GSmatrix4  Transform::getMatrix4() const
{
	GSmatrix4 mat = GS_MATRIX4_IDENTITY;
	mat.scale(m_Scale);
	mat.rotateYawPitchRoll(m_Rotate.y, m_Rotate.x, m_Rotate.z);
	mat.translate(m_Position);
	return mat;
}

const GSvector3 Transform::front() const
{
	GSmatrix4 m = getMatrix4();
	GSvector3 reslut =
	{
		m.m[2][0],m.m[2][1],m.m[2][2]
	};	
	return reslut;
}

const GSvector3 Transform::left() const
{
	GSmatrix4 m = getMatrix4();
	GSvector3 reslut =
	{
		m.m[0][0],m.m[0][1],m.m[0][2]
	};
	return reslut;
}

const GSvector3 Transform::up() const
{
	GSmatrix4 m = getMatrix4();
	GSvector3 reslut =
	{
		m.m[1][0],m.m[1][1],m.m[1][2]
	};
	return reslut;
}

const GSmatrix4 Transform::parentSynthesis(const Transform & parent)
{
	return getMatrix4()*parent.getMatrix4();
}
