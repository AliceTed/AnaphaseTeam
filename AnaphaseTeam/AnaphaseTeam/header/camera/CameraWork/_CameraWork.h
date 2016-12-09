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

class CameraWork : public I_CameraWork
{
public:
	/**
	@brief �R���X�g���N�^
	*/
	CameraWork(Camera* _camera);



	/**
	@brief �f�X�g���N�^
	*/
	~CameraWork() override;



	//�X�V����
	void update(float _deltaTime);



	//�`�揈��
	void draw(void);

private:
	//�J�������[�N�X�V����
	virtual void update_cameraWork(float _deltaTime);

	//�J�������[�N�`�揈��
	virtual void draw_cameraWork(void);

protected:
	Camera*								m_camera;			//�J����

	std::unique_ptr<CWParameterReader>	m_paramater_def;	//�J�����̒萔�p�����[�^

	GSvector3							m_offset_target;	//�^�[�Q�b�g�I�t�Z�b�g
};