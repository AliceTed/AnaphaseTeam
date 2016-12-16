/**
@file	SLookAt.h
@brief	�J�����̈ʒu���p�̕ϐ����܂Ƃ߂Ă邾��
@author Yuuho Aritomi
@date	2016/12/08
*/
#pragma once

#include <gslib.h>

class LookAt
{
public:
	GSvector3 position;			//**@brief �J�����̈ʒu
	GSvector3 position_offset;	//**@brief �ʒu�̃I�t�Z�b�g
	GSvector3 target;			//**@brief �����_
	GSvector3 target_offset;	//**@brief �����_�I�t�Z�b�g
	GSvector3 up;				//**@brief �J�����̏����
	GSmatrix4 mat_view;			//**@brief �V�F�[�_�[�p�̃��f���r���[�ϊ��s��

public:
	/**
	@brief �R���X�g���N�^
	@param[_position]	�ʒu
	@param[_target]		�^�[�Q�b�g
	@param[_up]			�J�����̏����
	*/
	LookAt(GSvector3 _position, GSvector3 _target, GSvector3 _up);

	//�f�X�g���N�^
	~LookAt();
};