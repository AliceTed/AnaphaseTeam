#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraTarget.h"

Camera::Camera(void) :
	m_perspective(Perspective(45.0f, 1280.0f / 720.0f, 0.3f, 1000.0f)),
	m_lookAt(LookAt(GSvector3(0, 0, 0), GSvector3(0, 0, 0), GSvector3(0, 1, 0))),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>())
{

}



Camera::Camera(
	const Perspective&	_perspective, 
	const GSvector3&	_position
) :
	m_perspective(_perspective),
	m_lookAt(LookAt(_position, _position + GSvector3(0, 0, -1), GSvector3(0, 1, 0))),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>())
{
}



Camera::~Camera()
{
}



void Camera::update(void)
{
	m_perspective.update();

	m_lookAt.update();

	return;
}



void Camera::move(const GSvector3& _position)
{
	m_lookAt.set_position(_position);

	return;
}



void Camera::lookAt(const GSvector3& _target)
{
	m_lookAt.lookAt(_target);

	return;
}



void Camera::lookAt_tilt(const GSvector3& _target, const float _direction)
{
	m_lookAt.lookAt_tilt(_target, _direction);

	return;
}



void Camera::lookAt_pan(const GSvector3& _target, const float _elevation)
{
	m_lookAt.lookAt_pan(_target, _elevation);

	return;
}



void Camera::lookAt_cameraTarget_player(const GSvector3& _target)
{
	m_cameraTarget_player->lookAt(_target);

	return;
}



void Camera::lookAt_cameraTarget_enemy(const GSvector3& _target)
{
	m_cameraTarget_enemy->lookAt(_target);

	return;
}



void Camera::follow_position(const GSvector3& _target, const float _speed)
{
	m_lookAt.follow_position(_target, _speed);
}



void Camera::follow_target(const GSvector3& _target, const float _speed)
{
	m_lookAt.follow_target(_target, _speed);
}



void Camera::zoom_reset(void)
{
	m_perspective.zoom_reset();
}



void Camera::zoom(const float _value)
{
	m_perspective.zoom(_value);
}



void Camera::zoom_in(const float _speed)
{
	m_perspective.zoom_in(_speed);
}



void Camera::zoom_out(const float _speed)
{
	m_perspective.zoom_out(_speed);
}



const GSvector3& Camera::cameraTarget_player() const
{
	return m_cameraTarget_player->_target();
}
const GSvector3& Camera::cameraTarget_enemy() const
{
	return m_cameraTarget_enemy->_target();
}



const bool Camera::isFrustumCulling(const GSvector3 & center, float radius) const
{
	//‹‘ä
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &m_lookAt.matView(), &m_perspective.matProj());

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}



const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohter‚ÆƒJƒƒ‰‚Ì‹——£
	float dis = ohter.distance(m_lookAt.position());
	//‹——£‚Ænear‚Ì·
	return dis-(m_perspective.near()+radius);
}



const float Camera::distance(const GSvector3 & ohter) const
{
	return m_lookAt.position().distance(ohter);
}



const Transform Camera::transform() const
{
	//yaw‰ñ“]‚¾‚¯
 	GSvector3 vec= m_lookAt.target() - m_lookAt.position();
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), m_lookAt.position());
}