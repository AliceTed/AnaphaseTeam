/******************************************************
@file	Camera.h
@brief	�J����
@author Yuuoh Aritomi : Matuo
@date	2016/09/23 Ver1.00
******************************************************/
#pragma once

#include <gslib.h>
#include <memory>
//#include "Perspective.h"
#include "LookAt.h"

#include "../../header/transform/Transform.h"

typedef GSvector4 Perspective;

class CameraTarget;

class Camera
{

public:
	/**************************************************
	@brief �R���X�g���N�^
	**************************************************/
	Camera(void);



	/**************************************************
	@brief �f�X�g���N�^
	**************************************************/
	~Camera();



	/**************************************************
	@brief �X�V����
	**************************************************/
	void update(void);



	/**************************************************
	@brief �w�肵���ʒu�Ɉړ�����
	@param[_position] �ʒu
	**************************************************/
	void move(const GSvector3& _position);



	/**************************************************
	@brief �J���������Ă���ʒu��ݒ肷��
	@param[_target] �^�[�Q�b�g
	**************************************************/
	void lookAt(const GSvector3& _target);



	/********************************************************
	@brief	�e�B���g�J�������[�N
	x����]�݂̂Ŕ�ʑ̂�����
	�i�����ƊȒP�ɂ�������j
	@param[_position_camera]	�J�����̈ʒu
	@param[_position_target]	�^�[�Q�b�g�̈ʒu
	@param[_direction]			���ʊp
	@param[_followSpeed_camera] �J�����̒ǔ����x
	@param[_followSpeed_target]	�^�[�Q�b�g�̒ǔ����x
	[0] �ǔ�����
	[0.1~0.9] �f�B���C����̒ǔ�
	[1] ���S�ǔ�
	********************************************************/
	void cameraWork_tilt(
		const GSvector3&	_position_camera,
		const GSvector3&	_position_target,
		const float			_direction,
		const float			_followSpeed_camera,
		const float			_followSpeed_target
	);
	
	
	
	/********************************************************
	@brief	�e�B���g�J�������[�N
	x����]�݂̂Ŕ�ʑ̂�����
	�i�����ƊȒP�ɂ�������j
	@param[_position_camera]	�J�����̈ʒu
	@param[_position_target]	�^�[�Q�b�g�̈ʒu
	@param[_elevation]			�p
	@param[_followSpeed_camera] �J�����̒ǔ����x
	@param[_followSpeed_target]	�^�[�Q�b�g�̒ǔ����x
	[0] �ǔ�����
	[0.1~0.9] �f�B���C����̒ǔ�
	[1] ���S�ǔ�
	********************************************************/
	void cameraWork_pan(
		const GSvector3& _position_camera,
		const GSvector3& _position_target,
		const float _elevation,
		const float _followSpeed_camera,
		const float _followSpeed_target
	);



	/********************************************************
	@brief	�J�������[�N�E�h���[
	�^�[�Q�b�g�ɒǏ]����
	@param[_position_target]	�^�[�Q�b�g�ʒu
	@param[_elevation]			�p
	@param[_direction]			���ʊp
	@param[_distance]			����
	@param[_followSpeed_camera]	�J�����̒ǔ����x
	@param[_followSpeed_target] �^�[�Q�b�g�̒ǔ����x
	********************************************************/
	void cameraWork_dolly(
		const GSvector3&	_position_target,
		const float			_elevation,
		const float			_direction,
		const float			_distance,
		const float			_followSpeed_camera,
		const float			_followSpeed_target
	);



	/**************************************************
	@brief �v���C���[�̈ʒu��ێ�
	@param[_target] �v���C���[�̈ʒu�����Ă�
	**************************************************/
	void lookAt_cameraTarget_player(const GSvector3& _target);



	/**************************************************
	@brief �G�l�~�[�̈ʒu��ێ�
	@param[_target] �G�l�~�[�̈ʒu�����Ă���
	**************************************************/
	void lookAt_cameraTarget_enemy(const GSvector3& _target);



	/**************************************************
	@brief �J�������^�[�Q�b�g�ɒǔ�
	@param[_target] �^�[�Q�b�g
	@param[_speed]	���x
					[0] �ǔ�����
					[1] �f�B���C����̒ǔ�
					[2] ���S�ǔ�
	**************************************************/
	void follow_position(const GSvector3& _target, const float _speed);



	/**************************************************
	@brief �����_���^�[�Q�b�g�ɒǔ�
	@param[_target] �^�[�Q�b�g
	@param[_speed]	���x
	[0] �ǔ�����
	[1] �f�B���C����̒ǔ�
	[2] ���S�ǔ�
	**************************************************/
	void follow_target(const GSvector3& _target, const float _speed);



	/*******************************************************
	@brief �g��͈͂�ݒ�
	@param[_min] �ŏ��l
	@param[_max] �ő�l
	*******************************************************/
	void zoom_clamp(
		const float _min,
		const float _max
	);



	/*******************************************************
	@brief �Y�[��
	@param[_value] �l
	*******************************************************/
	void zoom(const float _value);



	/*******************************************************
	@brief �Y�[���C��
	@param[_speed] ���x
	*******************************************************/
	void zoom_in(const float _speed);



	/*******************************************************
	@brief �Y�[���A�E�g
	@param[_speed] ���x
	*******************************************************/
	void zoom_out(const float _speed);



	/**************************************************
	@return �p�[�X�y�N�e�B�u
	**************************************************/
	const Perspective perspective(void) const
	{
		return m_perspective;
	}
	/**************************************************
	@return �ʒu
	**************************************************/
	const GSvector3 position(void) const
	{
		return m_lookAt.position();
	}
	/**************************************************
	@return �^�[�Q�b�g
	**************************************************/
	const GSvector3 target(void) const
	{
		return m_lookAt.target();
	}
	/**************************************************
	@return �J�����^�[�Q�b�g�i�v���C���[�j
	**************************************************/
	const GSvector3& cameraTarget_player(void) const;
	/**************************************************
	@return �J�����^�[�Q�b�g�i�G�l�~�[�j
	**************************************************/
	const GSvector3& cameraTarget_enemy(void) const;

	/**
	@author Matuo
	*/
	//void lookAt(const GSvector3& target, float dir);

	/**
	@author Matuo
	*/
	const bool isFrustumCulling(const GSvector3& center,float radius )const;

	/**
	@author Matuo
	*/
	const float nearDistance(const GSvector3& ohter,float radius)const;

	/**
	@author Matuo
	*/
	const float distance(const GSvector3& ohter)const;

	//��肠����
	const Transform transform()const;

private:
	void update_perspective(void);

	void update_zoom(const float _speed);

private:
	//Perspective						m_perspective;
	Perspective						m_perspective;
	float							m_fov_min;
	float							m_fov_max;
	GSmatrix4						m_matProjection;
	LookAt							m_lookAt;
	std::shared_ptr<CameraTarget>	m_cameraTarget_player;
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;
};