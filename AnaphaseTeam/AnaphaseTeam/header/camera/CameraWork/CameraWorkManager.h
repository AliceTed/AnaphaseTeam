/**
@file	CameraActionManager.h
@brief	�J�����A�N�V�����}�l�[�W���[
@author Yuuho Aritomi
@date	2016/11/14
*/
#pragma once

#include <unordered_map>
#include <memory>
#include <gslib.h>
#include "E_CameraWorkID.h"

class Camera;				//�J����
class CameraWorkData;		//�J�����f�[�^

class CameraWorkManager
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera]			�J����
	@param[_cameraTarget]	�J�����^�[�Q�b�g
	@param[_input]			�C���v�b�g
	*/
	CameraWorkManager(Camera* _camera);

	/**
	@brief �f�X�g���N�^
	**/
	~CameraWorkManager();

	/**
	@brief ���[�h
	*/
	void load(void);

	/**
	@brief �J�������[�N�̐؂�ւ�
	*/
	void change_cameraWork(const E_CameraWorkID _id);

	/**
	@brief �X�V����
	@param[_deltaTime] �P�t���[�����̕b��
	*/
	void update(float _deltaTime);

	/**
	@brief �`��
	*/
	void draw(void);

private:
	Camera*							m_camera;				//�J����

	std::unique_ptr<CameraWorkData> m_cameraData;			//�J�����f�[�^

	GSvector2						m_rotate;				//��]

	E_CameraWorkID					m_current_cameraWork;	//���݂̃J�������[�N
};