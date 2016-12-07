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
	m_target = _target;
}