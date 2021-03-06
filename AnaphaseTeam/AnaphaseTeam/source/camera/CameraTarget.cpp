#include "camera/CameraTarget.h"

CameraTarget::CameraTarget(void) :
	m_target(0.0f, 0.0f, 0.0f)
{

}


CameraTarget::~CameraTarget()
{

}


void CameraTarget::lookAt(const GSvector3& _target)
{
	//対象の位置を保持
	m_target = _target;
}

const GSvector3 & CameraTarget::_target(void) const
{
	//保持した位置を返す
	return m_target;
}
