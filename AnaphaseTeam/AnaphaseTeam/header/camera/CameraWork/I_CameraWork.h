/**
@file I_CameraWork.h
@brief �J�������[�N�C���^�[�t�F�C�X
@author Yuuho Aritomi
@date 2016/11/24
*/
#pragma once

#include <gslib.h>

class I_CameraWork
{
public:
	/**
	@brief �f�X�g���N�^
	*/
	virtual ~I_CameraWork()
	{

	}

	/**
	@brief[_deltaTime] �P�t���[�����̕b��
	*/
	virtual void run(float _deltaTime) = 0;
};