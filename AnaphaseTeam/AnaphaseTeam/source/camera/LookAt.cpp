#include "../../header/camera/LookAt.h"
#include "../../header/camera/ACalc.h"

LookAt::LookAt(void) :
	m_position		(0.0f, 0.0f, 0.0f),
	m_target		(0.0f, 0.0f, 0.0f),
	m_targetOffset	(0.0f, 0.0f, 0.0f),
	m_up			(0.0f, 0.0f, 0.0f),
	m_matView		(),
	m_elevation		(0.0f),
	m_direction		(0.0f)
{
	update();
	m_matView.identity();
}



LookAt::LookAt(
	const GSvector3& _position,
	const GSvector3& _target,
	const GSvector3& _up
) :
	m_position		(_position),
	m_target		(_target),
	m_targetOffset	(0.0f, 0.0f, 0.0f),
	m_up			(_up),
	m_matView		(),
	m_elevation		(0.0f),
	m_direction		(0.0f)
{
	update();
}



LookAt::~LookAt()
{

}



void LookAt::initialize(
	const GSvector3& _position,
	const GSvector3& _target,
	const GSvector3& _up
)
{
	m_position	= _position;
	m_target	= _target;
	m_up		= _up;

	return;
}



void LookAt::update(void)
{
	const GSvector3& position		= m_position;
	const GSvector3& target			= m_target;
	const GSvector3 targetOffset	= m_targetOffset - target;
	const GSvector3& up				= m_up;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		position.x,	position.y,	position.z,
		target.x + targetOffset.x,	target.y + targetOffset.y,	target.z + targetOffset.z,
		up.x,		up.y,		up.z
	);

	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&m_matView);

	to_eleDir(&m_elevation, &m_direction);

	return;
}



void LookAt::set_position(const GSvector3& _position)
{
	m_position = _position;

	return;
}




void LookAt::translate(const GSvector3& _vector)
{
	m_position += _vector;

	return;
}



void LookAt::lookAt(const GSvector3& _target)
{
	m_target		= _target;
	m_targetOffset	= _target;

	return;
}



void LookAt::lookAt_offset(const GSvector3& _target)
{
	m_targetOffset = _target;

	return;
}



void LookAt::cameraWork_tilt(
	const GSvector3& _position_camera,
	const GSvector3& _position_target,
	const float _direction,
	const float _followSpeed_camera,
	const float _followSpeed_target
)
{
	ACalc calc;
	float elevation, direction;
	GSvector3 vector, target;

	calc.vector(
		&vector, 
		_position_camera, 
		_position_target
	);

	gsVector3ToEleDir(
		&elevation,
		&direction,
		&vector
	);

	direction = _direction;

	to_radEleDir(&elevation, &direction);

	calc.rotate(
		&target,
		m_position,
		-elevation,
		direction,
		10
	);

	follow_position(_position_camera, _followSpeed_camera);

	follow_target(target, _followSpeed_target);

	return;
}



void LookAt::cameraWork_pan(
	const GSvector3& _position_camera,
	const GSvector3& _position_target,
	const float _elevation,
	const float _followSpeed_camera,
	const float _followSpeed_target
)
{
	ACalc calc;
	float elevation, direction;
	GSvector3 vector, target;

	calc.vector(
		&vector, 
		_position_camera, 
		_position_target
	);

	gsVector3ToEleDir(
		&elevation,
		&direction,
		&vector
	);

	elevation = _elevation;

	to_radEleDir(&elevation, &direction);

	calc.rotate(
		&target,
		m_position,
		elevation,
		direction,
		10
	);

	follow_position(_position_camera, _followSpeed_camera);

	follow_target(target, _followSpeed_target);
	
	return;
}



void LookAt::cameraWork_dolly(
	const GSvector3& _position_target,
	const float _elevation,
	const float _direction,
	const float _distance,
	const float _followSpeed_camera,
	const float _followSpeed_target
)
{
	ACalc calc;
	GSvector3 position;

	float elevation = _elevation;
	float direction = _direction;

	to_radEleDir(&elevation, &direction);

	calc.rotate(
		&position, 
		_position_target, 
		elevation, 
		direction, 
		_distance
	);

	follow_position(position, _followSpeed_camera);

	follow_target(_position_target, _followSpeed_target);

	return;
}



void LookAt::to_eleDir(float* _elevation, float* _direction)
{
	ACalc calc;
	GSvector3 vector;

	calc.vector(&vector, m_position, m_target);

	gsVector3ToEleDir(_elevation, _direction, &vector);

	return;
}



void LookAt::follow_position(const GSvector3& _target, const float _speed)
{
	ACalc calc;

	calc.tracking(&m_position, _target, _speed);

	return;
}



void LookAt::follow_target(const GSvector3& _target, const float _speed)
{
	ACalc calc;

	calc.tracking(&m_target, _target, _speed);

	m_targetOffset = m_target;

	return;
}



void LookAt::to_radEleDir(float* _elevation, float* _direction)
{
	ACalc calc;

	calc.to_rad(_elevation);
	calc.to_rad(_direction);

	return;
}



void LookAt::vector_p1_p2(
	GSvector3*			_vector,
	const GSvector3&	_p1,
	const GSvector3&	_p2
)
{
	(*_vector) = _p2 - _p1;
}