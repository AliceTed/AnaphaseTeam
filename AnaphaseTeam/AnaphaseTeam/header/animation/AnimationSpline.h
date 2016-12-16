/**
@file AnimationSpline.h
@brief �X�v���C���Ȑ��A�j���[�V����
@author Yuuho Aritomi
@date 2016/12/16
*/
#pragma once

#include <gslib.h>
class SplineVec3;

class AnimationSpline
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_sVec3]
	*/
	AnimationSpline(SplineVec3* _sVec3);

	//�f�X�g���N�^
	~AnimationSpline();

	/**
	@brief �o�ߎ��Ԃ̃��Z�b�g
	*/
	void resetTime(void);

	/**
	@brief ���s
	@param[_speed]���s���x
	@return ���x*/
	GSvector3 run(float _speed);

private:
	SplineVec3* m_sVec3;

	float m_timer;
};