#include "../../header/math/AMath.h"
#include <cmath>

const float AMath::PI = 3.14159265359f;

float AMath::to_rad(float _degree)
{
	float result = _degree;

	result *= PI / 180.0f;

	return result;
}

GSvector2 AMath::to_rad(const GSvector2& _rotate)
{
	GSvector2 result = {
		to_rad(_rotate.x),
		to_rad(_rotate.y)
	};

	return result;
}


float AMath::to_deg(float _radian)
{
	float result = _radian;

	result *= 180.0f / PI;

	return result;
}


float AMath::normalizeAngle(float _angle)
{
	return std::fmod(_angle, 360.0f);
}


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

GSvector3 AMath::vec3_vector(const GSvector3 _p1, const GSvector3 _p2)
{ 
	return _p2 - _p1;
}

GSvector3 AMath::vec3_center(const GSvector3 _p1, const GSvector3 _p2)
{
	return (_p1 + _p2) / 2;
}


GSvector3 AMath::rotate_sphericalCoordinates(
	const GSvector3& _center, 
	const GSvector2& _rotate, 
	const float _distance)
{
	GSvector3 result;

	result.x = _center.x + cosf(_rotate.y) * cosf(_rotate.x) * _distance;
	result.y = _center.y + sinf(_rotate.x) * _distance;
	result.z = _center.z + sinf(_rotate.y) * cosf(_rotate.x) * _distance;

	return result;
}

void AMath::lerp_eleDir(
	GSvector2*			_my,
	const GSvector2&	_target,
	float				_speed
)
{
	GSvector2 rotate = GSvector2(
		AMath::subtractAngle(_my->x, _target.x),
		AMath::subtractAngle(_my->y, _target.y)
	);

	(*_my) += rotate * _speed;

	return;
}

int AMath::side(const GSvector2 & _p, const GSvector2 & _start, const GSvector2 & _end)
{
	int n = _p.x * (_start.y - _end.y) + _start.x * (_end.y - _p.y) + _end.x * (_p.y - _start.y);
	n = n > 0 ? 1 : n;
	n = n < 0 ? -1 : n;
	n = n == 0 ? 0 : n;
	return n;
}
