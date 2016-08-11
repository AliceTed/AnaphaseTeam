#pragma once
#ifndef _SPOTLIGHT_H_
#define _SPOTLIGHT_H_
#include <gslib.h>
class SpotLight
{
public:
	SpotLight(GLenum _lightNo,
		const GSvector3&_direction,
		const GSvector3& _offset=GSvector3(0,0,0),
		float _cutoff=30.0f,
		float _exponet=20.0f);
	~SpotLight();
	void lighting(const GSvector3& _target);
private:
	GLenum m_LightNo;
	//!�ʒu�ɃI�t�Z�b�g
	GSvector3 m_Offset;
	//!�J�b�g�I�t�w��
	float m_Cutoff;
	//!�X�|�b�g���C�g�w��
	float m_Exponet;
	GSvector3 m_Direction;
};
#endif