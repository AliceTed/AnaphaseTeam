/****************************************************
@file	Controller.h
@brief	�J�����𑀍삷��
@author Yuho Artiomi
@date	2016-08-28 Ver1.00
****************************************************/

#pragma once

#include <gslib.h>
#include <memory>

class	Camera;
class	CameraActionManager;
enum	CameraActionID;

class CameraController
{

public:
	/***********************************************
	@brief �f�t�H���g�R���X�g���N�^
	@param[_camera] ���삷��J����
	***********************************************/
	CameraController(Camera* _camera);



	/***********************************************
	@brief �R���X�g���N�^
	@param[_camera]		�J����
	@param[_distance]	����
	@param[_elevation]	�p
	@param[_direction]	���ʊp
	***********************************************/
	CameraController(
		Camera* _camera, 
		const float _distance, 
		const float _elevation, 
		const float _direction
	);



	/***********************************************
	@brief �X�V����
	***********************************************/
	void update(void);



	/***********************************************
	@brief ���삷��J�����̕ύX
	@param[_camera] ���삷��J����
	***********************************************/
	void change_control(Camera* _camera);



	/***********************************************
	@brief ���s�E�J�����A�N�V����
	***********************************************/
	void run_cameraAction(const CameraActionID& _id);

private:
	Camera *m_camera;		// �����������J����
	float m_distance;		// �^�[�Q�b�g�Ƃ̋���
	float m_pitch;			// �s�b�`
	float m_yow;			// ���[

	std::shared_ptr<CameraActionManager> m_cameraActionManager;
};