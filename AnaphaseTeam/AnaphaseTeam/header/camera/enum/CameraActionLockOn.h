/****************************************************************
@file	CameraActionLockOn.h
@brief	���b�N�I�����̃J����
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include "../CameraAction.h"

class Camera;

class CameraActionLockOn : public CameraAction
{
public:
	/************************************************************
	@brief �R���X�g���N�^
	@param[_camera] �J����
	************************************************************/
	CameraActionLockOn(Camera* _camera);

	

	/************************************************************
	@brief �f�X�g���N�^
	************************************************************/
	~CameraActionLockOn();



	/************************************************************
	@brief ���s
	************************************************************/
	void run(void) override;

private:
	Camera* m_camera;
};