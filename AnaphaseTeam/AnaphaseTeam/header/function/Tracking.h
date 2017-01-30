/**
@file
@brief	�ǔ��N���X
@author Yuuho Aritomi
@date	2017/01/27*/
#pragma once

#include <gslib.h>

/**
@class
@brief �ǔ��N���X
*/
class Tracking
{
public:
	/**
	@fn
	@brief �ǔ�
	@param _my		�������I�u�W�F�N�g�̈ʒu
	@param _target	�^�[�Q�b�g
	@param _speed	�ǔ����x
					[0]		:�ǔ����Ȃ�
					[0<x<1]	:�������ǔ�
					[1]		:�ǔ�
	@return ����
	*/
	static GSvector3* tracking(GSvector3* _my, const GSvector3& _target, const float _speed);
};

