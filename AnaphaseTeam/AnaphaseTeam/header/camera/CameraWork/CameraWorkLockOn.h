/****************************************************************
@file	CameraActionLockOn.h
@brief	���b�N�I�����̃J����
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include <gslib.h>
#include "_CameraWork.h"

class CameraWorkLockOn : public CameraWork
{
public:
	/************************************************************
	@brief �R���X�g���N�^
	@param[_camera] �J����
	************************************************************/
	CameraWorkLockOn(Camera* _camera, GSvector2* _rotate);

	

	/************************************************************
	@brief �f�X�g���N�^
	************************************************************/
	~CameraWorkLockOn();

private:
	void draw_cameraWork(void) override;

private:
	GSvector2* m_rotate;
};