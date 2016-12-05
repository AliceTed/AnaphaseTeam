/******************************************************
@file	AMath.h
@brief	�v�Z
@author Yuuho Aritomi
@date	2016/12/02
******************************************************/
#pragma once

#include <gslib.h>

class AMath
{
public:
	/*************************************************
	@brief �~����
	*************************************************/
	static const float PI;

public:
	/*************************************************
	@brief ���W�A���ɕϊ�
	@param[_deg]	�p�x
	@return			���W�A���l
	*************************************************/
	static float to_rad(float _deg);

	/*************************************************
	@brief ���W�A���ɕϊ�
	@param[_rotate]		��]��
	@return				��]���i���W�A���ϊ��ς݁j
	*************************************************/
	static GSvector2 to_rad(const GSvector2& _rotate);

	/*************************************************
	@brief �p�x�ɕϊ�
	@param[_rad]	���W�A��
	@return			�p�x
	*************************************************/
	static float to_deg(float _rad);


	/*************************************************
	@brief �p�x�̐��K��
	@param[_angle]	�p�x
	@return			-360 ~ 360�܂ł̐��l
	*************************************************/
	static float normalizeAngle(float _angle);


	/*************************************************
	@brief �p�x�������߂�
	@param[_deg1]	�p�x�P	
	@param[_deg2]	�p�x�Q
	@return			�p�x
	*************************************************/
	static float subtractAngle(float _deg1, float _deg2);


	/*************************************************
	@brief ���ʍ��W���g������]
	@param[_center]		���S�_
	@param[_rotate]		��]�p�x
						x : �p
						y : ���ʊp
	@param[_distance]	���S����̋���
	*************************************************/
	static GSvector3 rotate_sphericalCoordinates(
		const GSvector3&	_center,
		const GSvector2&	_rotate,
		const float			_distance
	);


	/*************************************************
	@brief pitch,yow��]�̃��[�v
	@param[_my]			����
	@param[_target]		�^�[�Q�b�g
	@param[_speed]		���x
	*************************************************/
	static void lerp_eleDir(
		GSvector2*			_my,
		const GSvector2&	_target,
		float				_speed
	);
};

