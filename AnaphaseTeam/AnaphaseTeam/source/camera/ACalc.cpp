#include "../../header/camera/ACalc.h"
#include "../../header/math/Calculate.h"

const float ACalc::PI = 3.14159265359f;

ACalc::ACalc(void)
{

}



ACalc::~ACalc(void)
{

}


float ACalc::to_rad(float * _degree)
{
	return (*_degree) *= PI / 180.0f;
}


float ACalc::to_deg(float * _radian)
{
	return (*_radian) *= 180.0f / PI;
}
