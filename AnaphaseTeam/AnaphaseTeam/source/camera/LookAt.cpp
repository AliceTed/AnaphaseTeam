#include "../../header/camera/LookAt.h"

using namespace std;

LookAt::LookAt(void) :
	position(GSvector3(0.0f, 0.0f, 0.0f)),
	target(GSvector3(0.0f, 0.0f, 0.0f)),
	up(GSvector3(0.0f, 0.0f, 0.0f))
{
}

LookAt::LookAt(const GSvector3 * _position, const GSvector3 * _target, const GSvector3 * _up) :
	position((*_position)),
	target((*_target)),
	up((*_up))
{
}
