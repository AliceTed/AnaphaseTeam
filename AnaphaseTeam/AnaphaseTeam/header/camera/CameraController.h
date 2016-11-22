/****************************************************
@file	Controller.h
@brief	�J�����𑀍삷��
@author Yuho Artiomi
@date	2016-08-28 Ver1.00
****************************************************/

#pragma once

#include <gslib.h>
#include <memory>

class Camera;
class CameraActionManager;

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
	@brief ���삷��J�����̕ύX
	@param[_camera] ���삷��J����
	***********************************************/
	void change_control(Camera* _camera);



	/***********************************************
	@brief ����ȓG�Ɛ키���p
	@param[_target1] �����̓v���C���[�[�H
	@param[_Target2] �����ɋ���ȓG�̃x�N�^�[��n����
	***********************************************/
	void special_move1(
		GSvector3* _target1, 
		GSvector3* _target2, 
		float _elevation, 
		float _distance
	);



	/***********************************************
	@return ���ʊp
	***********************************************/
	const float direction(void) const;

private:
	Camera *m_camera;		// �����������J����
	float m_distance;		// �^�[�Q�b�g�Ƃ̋���
	float m_pitch;			// �s�b�`
	float m_yow;			// ���[

	std::shared_ptr<CameraActionManager> m_cameraActionManager;
};