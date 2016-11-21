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
class CameraAction;
class CameraActionData;

enum CameraActionID;

class CameraActionManager
{
public:
	/*****************************************
	@brief �R���X�g���N�^
	@param[_camera]			�J����
	@param[_cameraTarget]	�J�����^�[�Q�b�g
	@param[_input]			�C���v�b�g
	*****************************************/
	CameraActionManager(Camera* _camera);



	/*****************************************
	@brief �f�X�g���N�^
	*****************************************/
	~CameraActionManager();



	/*****************************************
	���[�h
	*****************************************/
	void load(void);



	/*****************************************
	@brief ���s
	*****************************************/
	void run(const CameraActionID& _id);

private:
	Camera*				m_camera;
	std::unique_ptr<CameraActionData> m_cameraData;
};