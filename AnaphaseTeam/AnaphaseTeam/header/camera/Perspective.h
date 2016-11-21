/***********************************************************
@file Perspective.h
@brief ���ߖ@
@author Yuho Artiomi
@data 2016-08-27 Ver1.00
***********************************************************/
#pragma once

#include <gslib.h>

class Perspective
{
public:
	//float fov;		/** @brief ���� */
	//float aspect;	/** @brief �� */
	//float near;		/** @brief �߂����� */
	//float far;		/** @brief �������� */

	/*******************************************************
	@brief �R���X�g���N�^
	*******************************************************/
	Perspective(void);

	/*******************************************************
	@brief �R���X�g���N�^
	@param[_fov]	����p
	@param[_aspect] �A�X�y�N�g
	@param[_near]	�߃N���b�v
	@param[_far]	���N���b�v
	*******************************************************/
	Perspective(
		const float _fov, 
		const float _aspect, 
		const float _near, 
		const float _far
	);



	/*******************************************************
	@brief �f�X�g���N�^
	*******************************************************/
	~Perspective();



	/*******************************************************
	@brief ������
	@param[_fov]	����p
	@param[_aspect] �A�X�y�N�g
	@param[_near]	�߃N���b�v
	@param[_far]	���N���b�v
	*******************************************************/
	void initialize(
		const float _fov,
		const float _aspect,
		const float _near,
		const float _far
	);



	/*******************************************************
	@brief �X�V
	*******************************************************/
	void update(void);



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



	/*******************************************************
	@return ����p
	*******************************************************/
	const float fov(void) const
	{
		return m_fov;
	}
	/*******************************************************
	@return �A�X�y�N�g
	*******************************************************/
	const float aspect(void) const
	{
		return m_aspect;
	}
	/*******************************************************
	@return �߃N���b�v
	*******************************************************/
	const float near(void) const
	{
		return m_near;
	}
	/*******************************************************
	@return ���N���b�v
	*******************************************************/
	const float far(void) const
	{
		return m_far;
	}
	/*******************************************************
	@return ���ˍs��
	*******************************************************/
	const GSmatrix4& matProj(void) const
	{
		return m_matProjection;
	}

private:
	//�Y�[������
	void zoom_update(const float _speed);

private:
	float		m_fov;
	float		m_aspect;
	float		m_near;
	float		m_far;

	GSmatrix4	m_matProjection;

	float		m_fov_min;
	float		m_fov_max;

	const float FOV_DEF = 90.0f;
	const float FOV_MIN = 0.1f;
	const float FOV_MAX = 360.0f;
};