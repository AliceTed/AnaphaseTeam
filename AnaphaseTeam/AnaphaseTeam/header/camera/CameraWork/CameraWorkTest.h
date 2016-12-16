/**
@file CameraWorkTest.h
@brief �J�������[�N�e�X�g
@author Yuuho Aritomi
@date 2016/12/12
*/
#pragma once

#include <vector>
#include <memory>
#include "CameraWorkEmpty.h"

class AnimationSpline;
class SplineVec3;

class CameraWorkTest : public CameraWorkEmpty
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera] �J����
	*/
	CameraWorkTest(Camera* _camera);

	//�f�X�g���N�^
	~CameraWorkTest() override;

	//�J�n����
	void start(void) override;

	//���s����
	void run(float _deltaTime) override;

private:
	int max_num;

	std::vector<GSvector3> points;

	std::shared_ptr<SplineVec3> vecs;

	std::unique_ptr<AnimationSpline> animSpline;
};