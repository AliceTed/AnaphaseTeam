/****************************************************
@file	CameraWork.h
@brief	�J�������[�N
@author Yuuho Aritomi
@date	2016/11/28
****************************************************/
#pragma once

#include <gslib.h>
#include <memory>
#include "I_CameraWork.h"

class Camera;
class CWParameterReader;

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

	std::unique_ptr<CWParameterReader>	m_paramater_def;

	GSvector3							m_offset_target;

	float m_deltaTime;
};