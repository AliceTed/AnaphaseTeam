/*********************************************
@file	CameraActionManager.h
@brief	�J�����A�N�V�����}�l�[�W���[
@author Yuuho Aritomi
@date	2016/11/14
*********************************************/
#pragma once

#include <unordered_map>
#include <memory>
#include <gslib.h>
#include "E_CameraWorkID.h"

class Camera;
class CameraWorkData;

class CameraWorkManager
{
public:
	/*****************************************
	@brief �R���X�g���N�^
	@param[_camera]			�J����
	@param[_cameraTarget]	�J�����^�[�Q�b�g
	@param[_input]			�C���v�b�g
	*****************************************/
	CameraWorkManager(Camera* _camera);



	/*****************************************
	@brief �f�X�g���N�^
	*****************************************/
	~CameraWorkManager();



	/*****************************************
	@brief ���[�h
	*****************************************/
	void load(void);



	/*****************************************
	@brief �J�������[�N�̐؂�ւ�
	*****************************************/
	void change_cameraWork(const E_CameraWorkID _id);



	/*****************************************
	@brief ���s
	*****************************************/
	void run(void);

private:
	Camera*							m_camera;

	std::unique_ptr<CameraWorkData> m_cameraData;

	GSvector2						m_rotate;

	E_CameraWorkID					m_current_cameraWork;
};