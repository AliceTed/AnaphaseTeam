#include "../../header/camera/Camera.h"
#include "../../header/camera/CameraTarget.h"
#include "../../header/math/Calculate.h"

Camera::Camera(void) :
	m_perspective(Perspective(45.0f, 1280.0f / 720.0f, 0.3f, 1000.0f)),
	//m_lookAt(LookAt(GSvector3(0, 0, 0), GSvector3(0, 0, 0), GSvector3(0, 1, 0))),
	m_position(0.0f, 0.0f, 0.0f),
	m_target(0.0f, 0.0f, 0.0f),
	m_up(0.0f, 1.0f, 0.0f),
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

	update_lookAt();

	return;
}



void Camera::move(const GSvector3& _position)
{
	m_position = _position;

	return;
}



void Camera::lookAt(const GSvector3& _target)
{
	m_target = _target;

	return;
}



void Camera::cameraWork_tilt_pan(
	const GSvector3& _position_camera,
	GSvector2 _rotate,
	const float _followSpeed_camera,
	const float _followSpeed_target
)
{
	GSvector3 target;

	to_rad(&_rotate.x);
	to_rad(&_rotate.y);

	update_rotate(
		&target,
		m_position,
		_rotate,
		10
	);

	follow_position(_position_camera, _followSpeed_camera);

	follow_target(target, _followSpeed_target);

	return;
}


void Camera::cameraWork_dolly(
	const GSvector3&	_position_target,
	GSvector2			_rotate,
	const float			_distance,
	const float			_followSpeed_camera,
	const float			_followSpeed_target
)
{
	GSvector3 position;

	to_rad(&_rotate.x);
	to_rad(&_rotate.y);

	update_rotate(
		&position,
		_position_target,
		_rotate,
		_distance
	);

	follow_position(position, _followSpeed_camera);

	follow_target(_position_target, _followSpeed_target);

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
	update_follow(&m_position, _target, _speed);

	return;
}



void Camera::follow_target(const GSvector3& _target, const float _speed)
{
	update_follow(&m_target, _target, _speed);

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
	//Ž‹‘ä
	GSfrustum frustum;
	gsFrustumFromMatrices(&frustum, &m_matView, &m_matProjection);

	return !!gsFrustumIsSphereInside(&frustum, &center, radius);
}



const float Camera::nearDistance(const GSvector3 & ohter, float radius) const
{
	//ohter‚ÆƒJƒƒ‰‚Ì‹——£
	float dis = ohter.distance(m_position);
	//‹——£‚Ænear‚Ì·
	return dis-(m_perspective.z + radius);
}



const float Camera::distance(const GSvector3 & ohter) const
{
	return m_position.distance(ohter);
}



const Transform Camera::transform() const
{
	//yaw‰ñ“]‚¾‚¯
 	GSvector3 vec= m_target - m_position;
	return Transform(vec.getYaw(), GSvector3(0, 1, 0), m_position);
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



void Camera::update_lookAt(void)
{
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(
		m_position.x,	m_position.y,	m_position.z,
		m_target.x,		m_target.y,		m_target.z,
		m_up.x,			m_up.y,			m_up.z
	);

	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)&m_matView);

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



void Camera::update_follow(
	GSvector3* _vector,
	const GSvector3& _target,
	float _speed
)
{
	Math::Clamp clamp;

	_speed = clamp(_speed, 0.0f, 1.0f);

	gsVector3Lerp(_vector, _vector, &_target, _speed);

	return;

}



void Camera::update_rotate(
	GSvector3* _vector,
	const GSvector3& _target,
	const GSvector2& _rotate,
	const float _distance
)
{
	_vector->x = _target.x + cosf(_rotate.y) * cosf(_rotate.x) * _distance;
	_vector->y = _target.y + sinf(_rotate.x) * _distance;
	_vector->z = _target.z + sinf(_rotate.y) * cosf(_rotate.x) * _distance;
}



void Camera::to_rad(float* _degree)
{
	float pi = 3.14159265359f;

	(*_degree) *= pi / 180.0f;

	return;
}