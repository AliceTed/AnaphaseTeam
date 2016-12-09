/**
@file	CameraWorkDead.h
@brief	�J�������[�N�i���S�j
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include "_CameraWork.h"

class CameraWorkDead : public CameraWork
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera] �J����
	*/
	CameraWorkDead(Camera* _camera);

	/**
	@brief �f�X�g���N�^
	*/
	~CameraWorkDead() override;

	//���s����
	void run(float _deltaTime) override;
};