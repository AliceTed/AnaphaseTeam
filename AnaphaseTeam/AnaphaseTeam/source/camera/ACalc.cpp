#include "../../header/camera/ACalc.h"
#include "../../header/math/Calculate.h"

ACalc::ACalc(void)
{

}



ACalc::~ACalc(void)
{

}



void ACalc::rotate(
	GSvector3*			_vector, 
	const GSvector3&	_target, 
	const float			_pitch, 
	const float			_yow, 
	const float			_distance)
{
	(*_vector).x = _target.x + cosf(_yow) * cosf(_pitch) * _distance;
	(*_vector).y = _target.y + sinf(_pitch) * _distance;
	(*_vector).z = _target.z + sinf(_yow) * cosf(_pitch) * _distance;

	return ;
}

void ACalc::tracking(
	GSvector3* _vector, 
	const GSvector3& _target, 
	const float _speed)
{
	Math::Clamp clamp;
	GSvector3 vector;
	float speed = _speed;

	speed = clamp(speed, 0.0f, 1.0f);

	gsVector3Lerp(_vector, _vector, &_target, _speed);

	return;
}

void ACalc::to_rad(float* _degree)
{
	(*_degree) *= 3.14f / 180.0f;

	return;
}

void ACalc::vector(
	GSvector3*			_vector, 
	const GSvector3&	_point_start, 
	const GSvector3&	_point_end)
{
	(*_vector) = _point_end - _point_start;
}
