#pragma once
#ifndef _DIRECTIONALLIGHT_H_
#define _DIRECTIONALLIGHT_H_
#include <gslib.h>
class DirectionalLight
{
public:
	DirectionalLight
	(
		GLenum _lightNo,
		const GSvector3& _direction, 
		const GSvector4& _ambient=GSvector4(0.3f,0.3f,0.3f,1.0f),
		const GSvector4& _diffuse=GSvector4(1.0f,1.0f,1.0f,1.0f),
		const GSvector4& _specular=GSvector4(1.0f, 1.0f, 1.0f, 1.0f)
	);
	~DirectionalLight();
	void lighting();
private:
	GLenum m_LightNo;

	GSvector4 m_Ambient;
	GSvector4 m_Diffuse;
	GSvector4 m_Specular;
	GSvector3 m_Direction;
};
#endif