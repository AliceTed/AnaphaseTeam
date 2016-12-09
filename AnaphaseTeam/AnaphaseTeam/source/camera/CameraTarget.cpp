#include "../../header/camera/CameraTarget.h"

CameraTarget::CameraTarget(void) :
	m_target(0.0f, 0.0f, 0.0f)
{

}


CameraTarget::~CameraTarget()
{

}


void CameraTarget::lookAt(const GSvector3& _target)
{
	//‘ÎÛ‚ÌˆÊ’u‚ğ•Û
	m_target = _target;
}

const GSvector3 & CameraTarget::_target(void) const
{
	//•Û‚µ‚½ˆÊ’u‚ğ•Ô‚·
	return m_target;
}
