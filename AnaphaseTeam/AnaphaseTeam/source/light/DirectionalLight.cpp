#include "../../header/light/DirectionalLight.h"

DirectionalLight::DirectionalLight
(
	GLenum _lightNo,
	const GSvector3& _direction,
	const GSvector4& _ambient,
	const GSvector4& _diffuse,
	const GSvector4& _specular
)
	:m_LightNo(_lightNo), 
	m_Direction(_direction),
	m_Ambient(_ambient), 
	m_Diffuse(_diffuse), 
	m_Specular(_specular)
{
}

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::lighting()
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*ŠÂ‹«Œõ*/
	glLightfv(m_LightNo, GL_AMBIENT, m_Ambient);
	/*ŠgŽU”½ŽËŒõ*/
	glLightfv(m_LightNo, GL_DIFFUSE, m_Diffuse);
	/*‹¾–Ê”½ŽËŒõ*/
	glLightfv(m_LightNo, GL_SPECULAR, m_Specular);
	/*ƒ‰ƒCƒg‚Ì•ûŒü w‚Ì’l‚ð0‚É‚·‚é‚±‚Æ‚Å•ûŒü‚ðŽ¦‚·*/
	glLightfv(m_LightNo, GL_POSITION, GSvector4(m_Direction, 0));

	glEnable(m_LightNo);
}