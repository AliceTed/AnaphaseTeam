/**
@file CameraWorkTest.h
@brief �J�������[�N�e�X�g
@author Yuuho Aritomi
@date 2016/12/12
*/
#pragma once

#include "CameraWorkEmpty.h"

class CameraWorkTest : public CameraWorkEmpty
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera] �J����
	*/
	CameraWorkTest(Camera* _camera);

	//�f�X�g���N�^
	~CameraWorkTest() override;

	//�J�n����
	void start(void) override;

	//���s����
	void run(float _deltaTime) override;
};