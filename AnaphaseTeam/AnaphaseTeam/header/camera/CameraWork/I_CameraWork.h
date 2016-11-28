/************************************************
@file I_CameraWork.h
@brief �J�������[�N�C���^�[�t�F�C�X
@author Yuuho Aritomi
@date 2016/11/24
************************************************/
#pragma once

#include <gslib.h>

class I_CameraWork
{
public:
	/********************************************
	@brief �f�X�g���N�^
	********************************************/
	virtual ~I_CameraWork()
	{

	}



	/********************************************
	@brief �X�V����
	@param[_deltaTime] 
	********************************************/
	virtual void update(float _deltaTime) = 0;



	/********************************************
	@brief �`�揈��
	********************************************/
	virtual void draw(void) = 0;
};