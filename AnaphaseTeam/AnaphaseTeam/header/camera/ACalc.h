/**
@file ACalc.h
@brief �v�Z����
@author Yuho Aritomi
@date 2016/09/21
*/

#pragma once

#include <gslib.h>

class ACalc
{
public:
	/**
	@brief �f�t�H���g�R���X�g���N�^
	*/
	ACalc(void);

	/**
	@brief �f�X�g���N�^
	*/
	~ACalc(void);

	/**
	@brief �^�[�Q�b�g�𒆐S�Ƃ�����]������
	*/
	static void rotate(GSvector3* _vector, const GSvector3* _target, const float _pitch, const float _yow, const float _distance);

	/**
	@brief �^�[�Q�b�g��ǔ�����
	@param[_speed] 
	[0~1]�͈̔͂Ŏw��i�͈͊O�̏ꍇ�͎��̎��̂悤�ɂȂ�܂���[a < 0 = 0],[a > 1 = 1]�j
	0�̏ꍇ			: �ǔ��������܂���
	0��1�ȊO�̏ꍇ  : �f�B���C���t�^���ꂽ�ǔ��ɂȂ�܂�
	1�̏ꍇ         : �f�B���C���t�^����Ă��Ȃ��ǔ��ɂȂ�܂�
	*/
	static void tracking(GSvector3* _vector, const GSvector3* _target, const float _speed);

	/**
	@brief ��̒l�̂����傫���ق���������
	*/
	static void max(int* _num, const int _a, const int _b);
	static void max(float* _num, const float _a, const float _b);

	/**
	@brief ��̒l�̂����������ق���������
	*/
	static void min(int* _num, const int _a, const int _b);
	static void min(float* _num, const float _a, const float _b);

	/**
	@brief �w�肵���l���ŏ��l�A�ő�l�𒴂��Ȃ��悤�ɂ���
	*/
	static void clamp(int* _num, const int _min, const int _max);
	static void clamp(float* _num, const float _min, const float _max);

	/**
	@brief �x�����W�A���ɕϊ�����
	*/
	static void to_rad(float* _degree);

	/**
	@brief �n�_����I�_�܂ł̌����Ƒ傫���𒲂ׂ�
	*/
	static void vector(GSvector3* _vector, const GSvector3* _start_point, const GSvector3* _end_point);
};