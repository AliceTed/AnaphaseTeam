/*************************************************
@file	CameraWorkNormal.h
@brief	�J�������[�N�E�m�[�}��
@author Yuuho Aritomi
@date	2016/11/28
*************************************************/
#pragma once

#include <gslib.h>
#include "CameraWork.h"

class CameraWorkNormal : public CameraWork
{
public:
	/*********************************************
	@brief �R���X�g���N�^
	*********************************************/
	CameraWorkNormal(Camera* _camera, GSvector2* _rotate);



	/*********************************************
	@brief �f�X�g���N�^
	*********************************************/
	~CameraWorkNormal() override;

private:
	void update(void) override;

	const GSvector2 velocity(void);

private:
	GSvector2* m_rotate;
};