/**
@file
@brief	�p�[�e�B�N���}�l�[�W���[
@author Yuuho Aritomi
@date	2017/01/31
*/
#pragma once

class IRenderer;

class ParticleManager
{
public:
	ParticleManager();
	~ParticleManager();
	void initialize();
	void update(float _deltaTime);
	void draw(IRenderer* _renderer);
};
