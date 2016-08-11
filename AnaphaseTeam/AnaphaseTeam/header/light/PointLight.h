#pragma once
#ifndef _POINTLIGHT_H_
#define _POINTLIGHT_H_
#include <gslib.h>
class PointLight
{
public:
	PointLight(GLenum _lightNo,const GSvector3& _offset);
	~PointLight();
	void lighting(const GSvector3& _target);
private:
	GLenum m_LightNo;
	GSvector3 m_Offset;
};
#endif