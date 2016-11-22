/******************************************************
@file .h
@brief �J����
@author Yuuoh Aritomi : Matuo
@date 2016/09/23 Ver1.00
******************************************************/
#pragma once

#include <gslib.h>
#include <memory>
#include "Perspective.h"
#include "LookAt.h"

#include "../../header/transform/Transform.h"

class CameraTarget;

class Camera
{

public:
	/**************************************************
	@brief �R���X�g���N�^
	**************************************************/
	Camera(void);



	/**************************************************
	@brief �R���X�g���N�^
	@param[_perspective]	�p�[�X�y�N�e�B�u
	@param[_position]		�ʒu
	**************************************************/
	Camera(
		const Perspective&	_perspective, 
		const GSvector3&	_position
	);



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



	/**************************************************
	@brief ������]�݂̂Ŕ�ʑ̂�����
	@param[_target] �^�[�Q�b�g
	@param[_direction] ���ʊp
	**************************************************/
	void lookAt_tilt(const GSvector3& _target, const float _direction);



	/**************************************************
	@brief y����]�݂̂Ŕ�ʑ̂�����
	@param[_target]		�^�[�Q�b�g
	@param[_elevation]	�p
	**************************************************/
	void lookAt_pan(const GSvector3& _target, const float _elevation);



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
	@brief �Y�[�����Z�b�g
	*******************************************************/
	void zoom_reset(void);



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
	Perspective						m_perspective;
	LookAt							m_lookAt;
	std::shared_ptr<CameraTarget>	m_cameraTarget_player;
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;
};