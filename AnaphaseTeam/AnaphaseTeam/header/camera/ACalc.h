/*****************************************************
@file	ACalc.h
@brief	�v�Z����
@author Yuho Aritomi
@date	2016/09/21
*****************************************************/

#pragma once

#include <gslib.h>

class ACalc
{
public:
	/*************************************************
	@brief �R���X�g���N�^
	*************************************************/
	ACalc(void);



	/*************************************************
	@brief �f�X�g���N�^
	*************************************************/
	~ACalc(void);



	/*************************************************
	@brief �^�[�Q�b�g�𒆐S�Ƃ�����]������
	@param[_vector]		�x�N�^�[
	@param[_target]		�^�[�Q�b�g
	@param[_elevation]	�p
	@param[_direction]	���ʊp
	@param[_distance]	����
	*************************************************/
	void rotate(
		GSvector3*			_vector, 
		const GSvector3&	_target, 
		const float			_elevation, 
		const float			_direction, 
		const float			_distance
	);



	/*************************************************
	@brief �^�[�Q�b�g��ǔ�����
	@param[_vector] �x�N�^�[
	@param[_target] �^�[�Q�b�g
	@param[_speed] 
	[0~1]�͈̔͂Ŏw��
	�͈͊O�̏ꍇ�͎��̎��̂悤�ɂȂ�܂��B
	��[a < 0 = 0],[a > 1 = 1]
	0�̏ꍇ			: �ǔ��������܂���
	0��1�ȊO�̏ꍇ  : �f�B���C���t�^���ꂽ
					  �ǔ��ɂȂ�܂��B
	1�̏ꍇ         : �f�B���C���t�^����Ă��Ȃ�
					  �ǔ��ɂȂ�܂��B
	*************************************************/
	static void tracking(
		GSvector3* _vector, 
		const GSvector3& _target, 
		const float _speed
	);



	/*************************************************
	@brief �x�����W�A���ɕϊ�����
	@param[_degree] �p�x
	*************************************************/
	static void to_rad(float* _degree);



	/*************************************************
	@brief �n�_����I�_�܂ł̌����Ƒ傫���𒲂ׂ�
	@param[_vector]			�x�N�^�[
	@param[_point_start]	�n�_�̈ʒu
	@param[_point_end]		�I�_�̈ʒu
	*************************************************/
	static void vector(
		GSvector3* _vector, 
		const GSvector3& _point_start, 
		const GSvector3& _point_end
	);
};