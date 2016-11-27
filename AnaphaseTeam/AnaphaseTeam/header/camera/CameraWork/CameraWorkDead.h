/*********************************************************************
@file	CameraWorkDead.h
@brief	�J�������[�N�i���S�j
@author Yuuho Aritomi
@date	2016/11/21
*********************************************************************/
#pragma once

#include "CameraWork.h"

class CameraWorkDead : public CameraWork
{
public:
	/*****************************************************************
	@brief �R���X�g���N�^
	@param[_camera] �J����
	*****************************************************************/
	CameraWorkDead(Camera* _camera);



	/*****************************************************************
	@brief �f�X�g���N�^
	*****************************************************************/
	~CameraWorkDead() override;

private:
	void update(void) override;
};