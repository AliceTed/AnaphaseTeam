/**
@file	CameraWork.h
@brief	�J�������[�N
@author Yuuho Aritomi
@date	2016/11/28
*/
#pragma once

#include <gslib.h>
#include <memory>
#include "I_CameraWork.h"

class Camera;				//�J����
class CWParameterReader;	//�J�������[�N�E�p�����[�^�ǂݍ��݋@

class CameraWorkEmpty : public I_CameraWork
{
public:
	/**
	@brief �R���X�g���N�^
	*/
	CameraWorkEmpty(Camera* _camera);

	/**
	@brief �f�X�g���N�^
	*/
	~CameraWorkEmpty() override;

	//�J�n����
	virtual void start(void) override;

	//���s����
	virtual void run(float _deltaTime) override;

protected:
	Camera*								m_camera;			//�J����

	std::unique_ptr<CWParameterReader>	m_paramater_def;	//�J�����̒萔�p�����[�^

	GSvector3							m_offset_target;	//�^�[�Q�b�g�I�t�Z�b�g
};