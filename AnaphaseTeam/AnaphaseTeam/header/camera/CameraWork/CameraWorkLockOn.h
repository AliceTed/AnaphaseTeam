/****************************************************************
@file	CameraActionLockOn.h
@brief	���b�N�I�����̃J����
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include "ICameraWork.h"

class Camera;

class CameraWorkLockOn : public ICameraWork
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



	/************************************************************
	@brief ���s
	************************************************************/
	void run(void) override;

private:
	Camera* m_camera;
};