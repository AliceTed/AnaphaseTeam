/*********************************************
@file	CameraActionManager.h
@brief	�J�����A�N�V�����}�l�[�W���[
@author Yuuho Aritomi
@date	2016/11/14
*********************************************/
#pragma once

#include <unordered_map>
#include <memory>

class Camera;
class CameraWorkData;

enum CameraWorkID;

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
	void change_cameraWork(const CameraWorkID& _id);



	/*****************************************
	@brief ���s
	*****************************************/
	void run(void);

private:
	Camera*				m_camera;
	std::unique_ptr<CameraWorkData> m_cameraData;
	CameraWorkID		m_current_cameraAction;
};