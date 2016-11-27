#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraTarget.h"
#include "../../header/math/Calculate.h"

Camera::Camera(void) :
	m_perspective(Perspective(45.0f, 1280.0f / 720.0f, 0.3f, 1000.0f)),
	m_lookAt(LookAt(GSvector3(0, 0, 0), GSvector3(0, 0, 0), GSvector3(0, 1, 0))),
	m_cameraTarget_player(std::make_shared<CameraTarget>()),
	m_cameraTarget_enemy(std::make_shared<CameraTarget>())
{

}



Camera::~Camera()
{
}



void Camera::update(void)
{
	update_perspective();

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



void Camera::cameraWork_tilt(
	const GSvector3&	_position_camera,
	const GSvector3&	_position_target,
	const float			_direction,
	const float			_followSpeed_camera,
	const float			_followSpeed_target
)
{
	m_lookAt.cameraWork_tilt(
		_position_camera,
		_position_target,
		_direction,
		_followSpeed_camera,
		_followSpeed_target
	);

	return;
}



void Camera::cameraWork_pan(
	const GSvector3&	_position_camera,
	const GSvector3&	_position_target,
	const float			_elevation,
	const float			_followSpeed_camera,
	const float			_followSpeed_target
)
{
	m_lookAt.cameraWork_pan(
		_position_camera,
		_position_target,
		_elevation,
		_followSpeed_camera,
		_followSpeed_target
	);

	return;
}


void Camera::cameraWork_dolly(
	const GSvector3&	_position_target,
	const float			_elevation,
	const float			_direction,
	const float			_distance,
	const float			_followSpeed_camera,
	const float			_followSpeed_target
)
{
	m_lookAt.cameraWork_dolly(
		_position_target,
		_elevation,
		_direction,
		_distance,
		_followSpeed_camera,
		_followSpeed_target
	);

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

	return;
}



void Camera::follow_target(const GSvector3& _target, const float _speed)
{
	m_lookAt.follow_target(_target, _speed);

	return;
}



void Camera::zoom_clamp(
	const float _min,
	const float _max
)
{
	m_fov_min = _min;
	m_fov_max = _max;

	return;
}



void Camera::zoom(const float _value)
{
	m_perspective.x = _value;
}



void Camera::zoom_in(const float _speed)
{
	update_zoom(-_speed);
}



void Camera::zoom_out(const float _speed)
{
	update_zoom(_speed);
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
	//éãêçë‰
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &m_lookAt.matView(), &m_matProjection);

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}



const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohterÇ∆ÉJÉÅÉâÇÃãóó£
	float dis = ohter.distance(m_lookAt.position());
	//ãóó£Ç∆nearÇÃç∑
	return dis-(m_perspective.z + radius);
}



const float Camera::distance(const GSvector3 & ohter) const
{
	return m_lookAt.position().distance(ohter);
}



const Transform Camera::transform() const
{
	//yawâÒì]ÇæÇØ
 	GSvector3 vec= m_lookAt.target() - m_lookAt.position();
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), m_lookAt.position());
}



void Camera::update_perspective(void)
{
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(
		m_perspective.x,
		m_perspective.y,
		m_perspective.z,
		m_perspective.w
	);

	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&m_matProjection);

	return;
}



void Camera::update_zoom(const float _speed)
{
	Math::Clamp clamp;
	
	m_perspective.x += _speed;

	m_perspective.x = clamp(
		m_perspective.x,
		m_fov_min,
		m_fov_max
	);

	return;
}