/**
@file Perspective.h
@brief ���ߖ@
@author Yuho Artiomi
@data 2016-08-27 Ver1.00
*/
#pragma once

class Perspective
{
public:
	float fov;		/** @brief ���� */
	float aspect;	/** @brief �� */
	float near;		/** @brief �߂����� */
	float far;		/** @brief �������� */

	/**
	@brief �f�t�H���g�R���X�g���N�^
	*/
	Perspective(void);

	/**
	@brief �R���X�g���N�^
	*/
	Perspective(const float _fov, const float _aspect, const float _near, const float _far);
};