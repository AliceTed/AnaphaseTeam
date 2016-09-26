/**
@file LookAt.h
@brief ��Œ��ׂ�
@author Yuho Aritomi
@date 2016/09/20 Ver 1.00
*/
#pragma once

#include <gslib.h>

class LookAt
{
public:
	GSvector3 position;	/** @brief �J�����̈ʒu */
	GSvector3 target;	/** @brief �����_�̈ʒu */
	GSvector3 up;		/** @brief �J�����̏㑤�̌��� */

	/**
	@brief �f�t�H���g�R���X�g���N�^
	*/
	LookAt(void);

	/**
	@brief �R���X�g���N�^
	@param[_position]	�ʒu
	@param[_target]		�����_
	@param[_up]			�J�����̏����
	*/
	LookAt(const GSvector3 *_position, const GSvector3 *_target, const GSvector3 *_up);
};
