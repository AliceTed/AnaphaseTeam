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



	//�X�V����
	void update(float _deltaTime);



	//�`�揈��
	void draw(void);

private:
	virtual void update_cameraWork(float _deltaTime);

	virtual void draw_cameraWork(void);

protected:
	Camera* m_camera;

	float m_deltaTime;
};