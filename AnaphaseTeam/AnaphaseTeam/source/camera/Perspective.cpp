#include "../../header/camera/Perspective.h"
#include "../../header/math/Calculate.h"

Perspective::Perspective(void) :
	m_fov(0.0f),
	m_aspect(0.0f),
	m_near(0.0f),
	m_far(0.0f)
{
	update();
}



Perspective::Perspective(
	const float _fov, 
	const float _aspect,
	const float _near, 
	const float _far
) :
	m_fov(_fov),
	m_aspect(_aspect),
	m_near(_near),
	m_far(_far)
{
	update();
}



Perspective::~Perspective()
{

}



void Perspective::initialize(
	const float _fov,
	const float _aspect,
	const float _near,
	const float _far
)
{
	m_fov		= _fov;
	m_aspect	= _aspect;
	m_near		= _near;
	m_far		= _far;

	return;
}



void Perspective::update(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(m_fov, m_aspect, m_near, m_far);

	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&m_matProjection);

	return;
}



void Perspective::zoom_reset(void)
{
	m_fov = FOV_DEF;

	update();
}



void Perspective::zoom(const float _value)
{
	Math::Clamp clamp;
	float value;

	value = clamp(_value, FOV_MIN, FOV_MAX);

	m_fov = value;

	update();

	return;
}



void Perspective::zoom_in(const float _speed)
{
	zoom_update(-_speed);

	return;
}



void Perspective::zoom_out(const float _speed)
{
	zoom_update(_speed);

	return;
}



void Perspective::zoom_update(const float _speed)
{

	Math::Clamp clamp;
	float* fov = &m_fov;

	m_fov += _speed;

	m_fov = clamp(m_fov, FOV_MIN, FOV_MAX);

	update();

	return;
}