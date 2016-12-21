/**
@file CameraWorkEvent.h
@brief �J�������[�N�E�C�x���g
@author Yuuho Aritomi
@date 2016/12/19
*/
#pragma once

#include <memory>
#include "CameraWorkEmpty.h"

class SplineAnimManager;

class CameraWorkEvent : public CameraWorkEmpty
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera] �J����
	*/
	CameraWorkEvent(Camera* _camera, SplineAnimManager* _splineAnimManager);

	//�f�X�g���N�^
	~CameraWorkEvent();

	//�J�n����
	void start(void) override;

	//���s����
	void run(float _deltaTime) override;

	//���̃J�������[�N
	std::string nextCameraWork(void);

	//�I���������H
	bool isEnd(void);

private:
	SplineAnimManager* m_splineAnimManager;
};