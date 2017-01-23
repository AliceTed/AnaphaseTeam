#include "..\..\header\math\Calculate.h"

const float Math::Calculate::PI = 3.14159265f;
GSvector2 Math::Calculate::wrap(const GSvector2 & _value, const GSvector2 & _low, const GSvector2 & _hight)
{
	GSvector2 res(0, 0);
	res.x = wrap(_value.x, _low.x, _hight.x);
	res.y = wrap(_value.y, _low.y, _hight.y);
	return res;
}

GSvector3 Math::Calculate::wrap(const GSvector3& _value, const GSvector3& _low, const GSvector3& _hight)
{
	GSvector3 res(0, 0, 0);
	res.x = wrap(_value.x, _low.x, _hight.x);
	res.y = wrap(_value.y, _low.y, _hight.y);
	res.z = wrap(_value.z, _low.z, _hight.z);
	return res;
}

GSvector2 Math::Calculate::clamp(const GSvector2 & value, const GSvector2 & low, const GSvector2 & hight)
{
	GSvector2 res(0, 0);
	gsVector2Maximize(&res, &value, &low);
	gsVector2Minimize(&res, &res, &hight);
	return res;
}

GSvector3 Math::Calculate::clamp(const GSvector3 & value, const GSvector3 & low, const GSvector3 & hight)
{
	GSvector3 res(0, 0, 0);
	gsVector3Maximize(&res, &value, &low);
	gsVector3Minimize(&res, &res, &hight);
	return res;
}

GSvector3 Math::Calculate::power(const GSvector3 & _start, const GSvector3 & _end, float _t, float _power)
{
	GSvector3 result;
	gsVector3Lerp(&result, &_start, &_end, pow(_t, _power));
	return result;
}
