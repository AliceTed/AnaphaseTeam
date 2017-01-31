/**
@file
@brief	�p�[�e�B�N��
@author Yuuho Aritomi
@date	2017/01/31
*/
#pragma once

#include <gslib.h>
#include "data/id/TEXTURE_ID.h"

class IRenderer;

/**
@class
@brief �p�[�e�B�N��
*/
class Particle
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
	*/
	Particle(const GSvector2 _pos, TEXTURE_ID _id = TEXTURE_ID::PARTICLE);
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~Particle();
	/**
	@fn
	@brief �X�V
	@param _deltaTime
	*/
	void update(float _deltaTime);
	/**
	@fn
	@brief �`��
	@param _renderer
	*/
	void draw(IRenderer* _renderer);
	/**
	@fn
	@brief ���񂾂��H
	@return ���񂾂��H
	*/
	bool isDead();
private:
	TEXTURE_ID m_texID;
	GSvector2 m_pos;
	GSvector2 m_pos_offset;
	float m_time;
	bool m_isDead;
	float m_speed;
};