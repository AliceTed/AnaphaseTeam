/**
@file	CameraWorkDead.h
@brief	�J�������[�N�i���S�j
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include "CameraWorkEmpty.h"

class CameraWorkDead : public CameraWorkEmpty
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera] �J����
	*/
	CameraWorkDead(Camera* _camera);

	//�f�X�g���N�^
	~CameraWorkDead() override;

	//�J�n����
	void start(void) override;

	//���s����
	void run(float _deltaTime) override;

	//���̃J�������[�N
	std::string nextCameraWork(void) override;

	//�I���������H
	bool isEnd(void) override;
private:
	float mTime;
};