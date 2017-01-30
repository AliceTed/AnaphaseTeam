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
	@fn
	@brief �R���X�g���N�^
	*/
	Shake();
	/**
	@fn
	@brief �f�X�g���N�^
	*/
	~Shake();
	/**
	@fn
	@brief ������
	@param _scale	�ӂ蕝
	@param _time	�U�鎞�ԁi�P�b���U�O�t���[���j
	@param _center	���_
	*/
	void init(const GSvector3& _scale, const int _time, const GSvector3& _center);
	/**
	@fn
	@brief ���s
	*/
	GSvector3 run();
	/**
	@fn
	@brief ���Ԃ�������
	*/
	void resetTime(void);
private:
	std::unique_ptr<AnimationSpline> animSpline;	//�X�v���C���A�j���[�V����
};