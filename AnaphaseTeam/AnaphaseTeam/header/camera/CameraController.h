/**
@file	Controller.h
@brief	�J�����𑀍삷��
@author Yuho Artiomi
@date	2016-08-28 Ver1.00
*/
#pragma once

#include <gslib.h>
#include <memory>

#include "CameraWork\E_CameraWorkID.h"

class	Camera;
class	CameraWorkManager;
enum	CameraWorkID;

class CameraController
{

public:
	/**
	@brief �f�t�H���g�R���X�g���N�^
	@param[_camera] ���삷��J����
	*/
	CameraController(Camera* _camera);

	//�f�X�g���N�^
	~CameraController();

	/**
	@brief �X�V����
	@param[_deltaTime] �P�t���[�����̕b��
	*/
	void update(float _deltaTime);

	/**
	@brief �`�揈��
	*/
	void draw(void);

	/**
	@brief �J�������[�N�̏�Ԃ�؂�ւ���
	@param[_id] �J�������[�N�h�c
	*/
	void change_cameraWork(const E_CameraWorkID _id);

private:
	std::shared_ptr<CameraWorkManager> m_cameraWorkManager;	//�J�������[�N�E�}�l�[�W���[ 

	float m_deltaTime;										//�P�t���[�����̕b��
};