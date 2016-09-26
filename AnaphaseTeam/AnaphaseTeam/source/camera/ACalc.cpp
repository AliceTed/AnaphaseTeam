#include "../../header/camera/ACalc.h"

ACalc::ACalc(void)
{
}

ACalc::~ACalc(void)
{
}

void ACalc::rotate(GSvector3* _vector, const GSvector3 *_target, const float _pitch, const float _yow, const float _distance)
{
	(*_vector).x = (*_target).x + cosf(_yow) * cosf(_pitch) * _distance;
	(*_vector).y = (*_target).y + sinf(_pitch) * _distance;
	(*_vector).z = (*_target).z + sinf(_yow) * cosf(_pitch) * _distance;

	return ;
}

void ACalc::tracking(GSvector3* _vector, const GSvector3 *_target, const float _speed)
{
	GSvector3 vector;
	float speed = _speed;

	clamp(&speed, 0.0f, 1.0f);

	vector = (*_target) - (*_vector);
	(*_vector) += vector * speed;

	return;
}

void ACalc::max(int* _num, const int _a, const int _b)
{
	(*_num) = _a > _b ? _a : _b;

	return;
}

void ACalc::max(float* _num, const float _a, const float _b)
{
	(*_num) = _a > _b ? _a : _b;

	return;
}


void ACalc::min(int* _num, const int _a, const int _b)
{
	(*_num) = _a > _b ? _b : _a;

	return;
}

void ACalc::min(float* _num, const float _a, const float _b)
{
	(*_num) = _a > _b ? _b : _a;

	return;
}

void ACalc::clamp(int* _num, const int _min, const int _max)
{
	min(_num, (*_num), _max);
	max(_num, (*_num), _min);

	return;
}

void ACalc::clamp(float* _num, const float _min, const float _max)
{
	min(_num, (*_num), _max);
	max(_num, (*_num), _min);

	return;
}

void ACalc::to_rad(float* _degree)
{
	(*_degree) *= 3.14f / 180.0f;

	return;
}

void ACalc::vector(GSvector3* _vector, const GSvector3* _start_point, const GSvector3* _end_point)
{
	(*_vector) = (*_end_point) - (*_start_point);
}
