#include "../../header/camera/AMath.h"
#include <cmath>

const float AMath::PI = 3.14159265359f;

float AMath::to_rad(float _degree)
{
	float result = _degree;

	result *= PI / 180.0f;

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
