/**
@file
@brief ���j���[�p�p�[�e�B�N��
@author Yuuho Aritomi
@date 2017/01/31
*/
#pragma once

#include <gslib.h>
#include <memory>
#include "data/id/TEXTURE_ID.h"

class IRenderer;
class ParticleManager;
/**
@class
@brief ���j���[�p�p�[�e�B�N��
*/
class MenuParticle
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
	*/
	MenuParticle();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~MenuParticle();
	/**
	@fn
	@brief ������
	*/
	void initialize();
	/**
	@fn
	@brief �X�V
	*/
	void update(float _deltaTime);
	/**
	@fn
	@brief �`��*/
	void draw(IRenderer* _renderer);
	/**
	@fn
	@brief �I������
	*/
	void finish();
private:
	std::unique_ptr<ParticleManager> m_particle;
};