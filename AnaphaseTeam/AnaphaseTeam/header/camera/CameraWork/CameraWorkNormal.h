/*************************************************
@file	CameraWorkNormal.h
@brief	�J�������[�N�E�m�[�}��
@author Yuuho Aritomi
@date	2016/11/28
*************************************************/
#pragma once

#include <gslib.h>
#include "I_CameraWork.h"

class Camera;

class CameraWorkNormal : public I_CameraWork
{
public:
	/*********************************************
	@brief �R���X�g���N�^
	*********************************************/
	CameraWorkNormal(Camera* _camera);



	/*********************************************
	@brief �f�X�g���N�^
	*********************************************/
	~CameraWorkNormal() override;



	/*********************************************
	@brief ���s
	*********************************************/
	void run(void) override;

private:
	const GSvector2 velocity(void);

private:
	Camera* m_camera;

	GSvector2 m_rotate;
};