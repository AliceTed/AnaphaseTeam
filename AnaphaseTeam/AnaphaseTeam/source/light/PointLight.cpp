#include "../../header/light/PointLight.h"


PointLight::PointLight(GLenum _lightNo, const GSvector3& _offset)
	:m_LightNo(_lightNo), m_Offset(_offset)
{
}

PointLight::~PointLight()
{
}

void PointLight::lighting(const GSvector3& _target)
{
	/*���C�g�̈ʒu,��w�̒l��1�ɂ��邱�Ƃňʒu������*/
	glLightfv(m_LightNo, GL_POSITION, GSvector4(_target + m_Offset, 1.0f));
	glEnable(m_LightNo);
}
