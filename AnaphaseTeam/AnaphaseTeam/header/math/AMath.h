/******************************************************
@file	AMath.h
@brief	�v�Z
@author Yuuho Aritomi
@date	2016/12/02
******************************************************/
#pragma once

#include <gslib.h>
#include <list>
#include <vector>

class AMath
{
public:
	/**
	@brief �~����
	*/
	static const float PI;

public:
	/**
	@brief ���W�A���ɕϊ�
	@param[_deg]	�p�x
	@return			���W�A���l
	*/
	static float to_rad(float _deg);

	/**
	@brief ���W�A���ɕϊ�
	@param[_rotate]		��]��
	@return				��]���i���W�A���ϊ��ς݁j
	*/
	static GSvector2 to_rad(const GSvector2& _rotate);

	/**
	@brief �p�x�ɕϊ�
	@param[_rad]	���W�A��
	@return			�p�x
	*/
	static float to_deg(float _rad);

	/**
	@brief �p�x�̐��K��
	@param[_angle]	�p�x
	@return			-360 ~ 360�܂ł̐��l
	*/
	static float normalizeAngle(float _angle);

	/**
	@brief �p�x�������߂�
	@param[_deg1]	�p�x�P	
	@param[_deg2]	�p�x�Q
	@return			�p�x
	*/
	static float subtractAngle(float _deg1, float _deg2);

	/**
	@brief �Q�_�Ԃ̂R�����x�N�g�������߂�
	@param[_p1] �_�P
	@param[_p2] �_�Q
	@return		�R�����x�N�g��
	*/
	static GSvector3 vec3_vector(const GSvector3 _p1, const GSvector3 _p2);

	/**
	@brief �Q�_�Ԃ̒��_�����߂�
	@param[_p1] �_�P
	@param[_p2] �_�Q
	@return		���_
	*/
	static GSvector3 vec3_center(const GSvector3 _p1, const GSvector3 _p2);

	/**
	@brief ���ʍ��W���g������]
	@param[_center]		���S�_
	@param[_rotate]		��]�p�x
						x : �p
						y : ���ʊp
	@param[_distance]	���S����̋���
	*/
	static GSvector3 ballRotate(
		const GSvector3&	_center,
		const GSvector2&	_rotate,
		const float			_distance
	);

	/**
	@brief pitch,yow��]�̃��[�v
	@param[_my]			����
	@param[_target]		�^�[�Q�b�g
	@param[_speed]		���x
	*/
	static void lerp_eleDir(
		GSvector2*			_my,
		const GSvector2&	_target,
		float				_speed
	);

	/**
	@brief �_�����L�������̍��E�ǂ���ɂ��邩�𒲂ׂ�
	@param[_p]		�_��
	@param[_start]	�L�������n�_
	@param[_end]	�L�������I�_
	@return			�����F�P
					������F�O
					�E���F�|�P
	*/
	static int side(
		const GSvector2& _p,
		const GSvector2& _start,
		const GSvector2& _end
	);

	/**
	@brief ���l�̂�������߂�
	@param[_num]	���l
	@param[_n]		n��
	@return ����
	*/
	static float pow(float _num, int _n);

	/**
	@brief �h�ꏈ��
	@param[_scale]	�h�ꕝ
	@param[_t]		(��)		
	@return ���߂��h�ꕝ�i���j
	*/
	static GSvector3 shake();
};
