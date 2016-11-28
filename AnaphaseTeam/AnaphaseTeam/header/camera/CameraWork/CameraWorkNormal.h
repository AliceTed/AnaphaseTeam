/*************************************************
@file	CameraWorkNormal.h
@brief	�J�������[�N�E�m�[�}��
@author Yuuho Aritomi
@date	2016/11/28
*************************************************/
#pragma once

#include <memory>
#include "_CameraWork.h"

class CWParameterReader;

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

	std::unique_ptr<CWParameterReader> m_parameter;

	float m_speed_input;
	float m_distance;
	float m_followSpeed_position;
	float m_followSpeed_target;
};