/**
@file	CameraWorkNormalBattle
@brief	�J�����ʏ�퓬
@author	Yuuho Aritomi
@date	2016/12/19
*/
#pragma once

#include <memory>
#include "CameraWorkEmpty.h"

class CameraWorkNormalBattle : public CameraWorkEmpty
{
public:
	CameraWorkNormalBattle(Camera* _camera, bool* _isLockOn);

	//�f�X�g���N�^
	~CameraWorkNormalBattle() override;

	//�J�n����
	void start(void) override;

	//���s����
	void run(float _deltaTime) override;

private:
	GSvector2 m_rotate;
	std::unique_ptr<CameraWorkEmpty> m_normal;
	std::unique_ptr<CameraWorkEmpty> m_lockon;
	bool* m_isLockOn;
};