/**********************************************
@file	CameraActionDolly.h
@brief	�J�����̈ړ��B�e
@author Yuuho Aritomi
@date	2016/11/14
**********************************************/
#pragma once

#include "CameraWork/I_CameraWork.h"
#include <gslib.h>

class Camera;

class CameraActionDolly : public I_CameraWork
{
public:
	/******************************************
	@brief �R���X�g���N�^
	@param[_camera]			�J����
	@param[_target]			�J�����^�[�Q�b�g
	@param[_elevation]		�p
	@param[_direction]		���ʊp
	******************************************/
	CameraActionDolly(
		Camera*			_camera,
		GSvector3*		_target,
		float*			_elevation,
		float*			_direction);



	/******************************************
	@brief �f�X�g���N�^
	******************************************/
	virtual ~CameraActionDolly() override;



	/******************************************
	@brief ������
	@param[_distance]	����
	******************************************/
	void initialize(const float _distance);



	/******************************************
	@brief ���s
	******************************************/
	void run(void) override;

protected:

private:
	Camera*		m_camera;			//�J����
	GSvector3*	m_target;			//�J�����^�[�Q�b�g
	float*		m_elevation;		//�p
	float*		m_direction;		//���ʊp
	float		m_distance;			//**@brief ����
};