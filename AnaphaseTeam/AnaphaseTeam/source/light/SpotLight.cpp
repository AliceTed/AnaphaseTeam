#include "../../header/light/SpotLight.h"
SpotLight::SpotLight
(
	GLenum _lightNo,
	const GSvector3& _direction,
	const GSvector3& _offset,
	float _cutoff, 
	float _exponet
	)
	:m_LightNo(_lightNo),
	m_Direction(_direction),
	m_Offset(_offset),
	m_Cutoff(_cutoff),
	m_Exponet(_exponet)
{
}

SpotLight::~SpotLight()
{
}

void SpotLight::lighting(const GSvector3& _target)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLightfv(m_LightNo, GL_SPOT_DIRECTION, GSvector4(m_Direction, 1.0f));/*•ûŒü*/
	glLightf(m_LightNo, GL_SPOT_CUTOFF, m_Cutoff);
	glLightf(m_LightNo, GL_SPOT_EXPONENT, m_Exponet);

	glLightfv(m_LightNo, GL_POSITION, GSvector4(_target + m_Offset, 1.0f));

	glEnable(m_LightNo);
}
