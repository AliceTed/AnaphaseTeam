/**
@file	Shake.h
@brief	�V�F�C�N�����i�ׂ��������͕����Ȃ���j
@author Yuuho Aritomi
@date	2016/12/16
*/
#pragma once

#include <gslib.h>
#include <vector>
#include <memory>

class AnimationSpline;
class SplineVec3;

class Shake
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_scale]	�ӂ蕝
	@param[_time]	�U�鎞�ԁi�P�b���U�O�t���[���j
	*/
	Shake(const GSvector3& _scale, float _time);

	//�f�X�g���N�^
	~Shake();

	/**
	@brief ���s
	@param[_speed] ���s���x
	@param[_center]���_
	@return ���߂��ʒu�@�{�@���_
	*/
	GSvector3 run(float _speed, const GSvector3& _center = { 0.0f, 0.0f, 0.0f });

	/**
	@brief ���Ԃ�������
	*/
	void resetTime(void);

private:
	std::vector<GSvector3> points;					//�e�_

	std::unique_ptr<AnimationSpline> animSpline;	//�X�v���C���A�j���[�V����
};