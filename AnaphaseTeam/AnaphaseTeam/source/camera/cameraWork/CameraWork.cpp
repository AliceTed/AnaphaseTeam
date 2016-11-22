#include "../../../header/camera/cameraWork/CameraWork.h"
#include "../../../header/camera/Camera.h"

CameraWork::CameraWork(Camera* _camera) :
	m_camera(_camera)
{

}



CameraWork::~CameraWork()
{

}



void CameraWork::initialize(
	const GSvector3& _position,
	const GSvector3& _target
)
{
	initialize_position(_position.x, _position.y, _position.z);

	initialize_target(_target.x, _target.y, _target.z);

	return;
}



const GSvector3& CameraWork::initialize_position(
	const float _x,
	const float _y,
	const float _z
)
{
	GSvector3 position = GSvector3(_x, _y, _z);

	m_position = position;

	return m_position;
}



const GSvector3& CameraWork::initialize_target(
	const float _x,
	const float _y,
	const float _z
)
{
	GSvector3 target = GSvector3(_x, _y, _z);

	m_target = target;

	return m_target;
}