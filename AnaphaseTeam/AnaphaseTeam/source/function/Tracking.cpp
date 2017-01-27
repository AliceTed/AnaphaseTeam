#include "function/Tracking.h"



//’Ç”ö
GSvector3 * Tracking::tracking(GSvector3 * _my, const GSvector3 & _target, const float _speed)
{
	return gsVector3Lerp(_my, _my, &_target, _speed);
}
