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
	/*環境光*/
	glLightfv(m_LightNo, GL_AMBIENT, m_Ambient);
	/*拡散反射光*/
	glLightfv(m_LightNo, GL_DIFFUSE, m_Diffuse);
	/*鏡面反射光*/
	glLightfv(m_LightNo, GL_SPECULAR, m_Specular);
	/*ライトの方向 wの値を0にすることで方向を示す*/
	glLightfv(m_LightNo, GL_POSITION, GSvector4(m_Direction, 0));

	glEnable(m_LightNo);
}