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
class CameraActionDolly;

typedef std::shared_ptr<CameraAction> cameraAction_ptr;
typedef std::unordered_map<int, cameraAction_ptr> cameraAction_map;

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
	void run(void);

private:
	Camera*				m_camera;
	cameraAction_map	m_cameraActions;

	float m_elevation;
	float m_direction;
};