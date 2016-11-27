/****************************************************************
@file	CameraActionLockOn.h
@brief	���b�N�I�����̃J����
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include "CameraWork.h"

class CameraWorkLockOn : public CameraWork
{
public:
	/************************************************************
	@brief �R���X�g���N�^
	@param[_camera] �J����
	************************************************************/
	CameraWorkLockOn(Camera* _camera);

	

	/************************************************************
	@brief �f�X�g���N�^
	************************************************************/
	~CameraWorkLockOn();

private:
	void update(void) override;
};