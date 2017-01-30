#include "math/AMath.h"
#include "math/Calculate.h"
#include <cmath>
#include <algorithm>

const float AMath::PI = 3.14159265359f;

//���W�A���ɕϊ��iGSvector2�p�j
GSvector2 AMath::to_rad(const GSvector2& _rotate)
{
	GSvector2 result = {
		Math::Calculate::degTorad(_rotate.x),
		Math::Calculate::degTorad(_rotate.y),
	};
	return result;
}

//�p�x�̐��K��
float AMath::normalizeAngle(float _angle)
{
	return std::fmod(_angle, 360.0f);
}

//�p�x�������߂�
float AMath::subtractAngle(float _deg1, float _deg2)
{
	float d = normalizeAngle(_deg2 - _deg1);

	if (d > 180.0f)
	{
		d -= 360.0f;
	}
	else if (d < -180.0f)
	{
		d += 360.0f;
	}

	return d;
}

//�Q�_�Ԃ̂R�����x�N�g�������߂�
GSvector3 AMath::vec3_vector(const GSvector3 _p1, const GSvector3 _p2)
{
	return _p2 - _p1;
}

//�Q�_�Ԃ̒��_�����߂�
GSvector3 AMath::vec3_center(const GSvector3 _p1, const GSvector3 _p2)
{
	return (_p1 + _p2) / 2;
}

//���ʍ��W���g������]
GSvector3 AMath::ballRotate(const GSvector3& _center, const GSvector2& _rotate, const float _distance)
{
	GSvector3 result;
	result.x = _center.x + cosf(_rotate.y) * cosf(_rotate.x) * _distance;
	result.y = _center.y + sinf(_rotate.x) * _distance;
	result.z = _center.z + sinf(_rotate.y) * cosf(_rotate.x) * _distance;
	return result;
}

//��]�̃��[�v
void AMath::lerp_angle(float * _my, const float _target, const float _speed)
{
	float subAng = AMath::subtractAngle((*_my), _target);
	(*_my) += subAng * _speed;
}

//pitch,yow��]�̃��[�v
void AMath::lerp_eleDir(GSvector2* _my, const GSvector2& _target, const float _speed)
{
	lerp_angle(&_my->x, _target.x, _speed);
	lerp_angle(&_my->y, _target.y, _speed);
}

//�_�����L�������̍��E�ǂ���ɂ��邩�𒲂ׂ�
int AMath::side(const GSvector2 & _p, const GSvector2 & _start, const GSvector2 & _end)
{
	int n = _p.x * (_start.y - _end.y) + _start.x * (_end.y - _p.y) + _end.x * (_p.y - _start.y);
	n = n > 0 ? 1 : n;
	n = n < 0 ? -1 : n;
	n = n == 0 ? 0 : n;
	return n;
}

//���l�̂�������߂�
float AMath::pow(float _num, int _n)
{
	float result = 1;
	for (int i = 0; i < _n; i++)
	{
		result *= _num;
	}
	return result;
}
