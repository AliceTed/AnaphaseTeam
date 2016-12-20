/**
@file AnimationSpline.h
@brief �X�v���C���Ȑ��A�j���[�V����
@author Yuuho Aritomi
@date 2016/12/16
*/
#pragma once

#include <gslib.h>
#include <memory>
#include <vector>

class SplineVec3;

class AnimationSpline
{
public:

	/**
	@brief �R���X�g���N�^
	*/
	AnimationSpline(void);

	//�f�X�g���N�^
	~AnimationSpline();

	/**
	@brief ������
	@param[_points] �e�_
	*/
	void init(const std::vector<GSvector3>& _points);

	/**
	@brief �o�ߎ��Ԃ̃��Z�b�g
	*/
	void resetTime(void);

	/**
	@brief ���s
	@param[_speed]���s���x
	@param[_center]���_
	@return ���߂��ʒu�@�{�@���_
	*/
	GSvector3 run(float _speed, const GSvector3& _center = { 0.0f, 0.0f, 0.0f });

	/**
	@return �I���������H
	*/
	bool isEnd(void);

private:
	std::unique_ptr<SplineVec3> m_sVec3;

	float m_timer;
};