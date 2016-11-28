/****************************************************
@file	CameraWork.h
@brief	�J�������[�N
@author Yuuho Aritomi
@date	2016/11/28
****************************************************/
#pragma once

#include "I_CameraWork.h"

class Camera;

class CameraWork : public I_CameraWork
{
public:
	/************************************************
	@brief �R���X�g���N�^
	************************************************/
	CameraWork(Camera* _camera);



	/************************************************
	@brief �f�X�g���N�^
	************************************************/
	~CameraWork() override;



	/************************************************
	@brief ���s
	************************************************/
	void run(void) override;

private:
	virtual void update(void);

protected:
	Camera* m_camera;
};