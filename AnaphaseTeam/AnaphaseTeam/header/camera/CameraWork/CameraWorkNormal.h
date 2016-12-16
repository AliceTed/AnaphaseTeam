/**
@file	CameraWorkNormal.h
@brief	�J�������[�N�E�m�[�}��
@author Yuuho Aritomi
@date	2016/11/28
*/
#pragma once

#include <memory>
#include "CameraWorkEmpty.h"

class CWParameterReader;	//�J�������[�N�̃p�����[�^�̓ǂݍ��݋@

class CameraWorkNormal : public CameraWorkEmpty
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera] �J����
	@param[_rotate] ��]
	*/
	CameraWorkNormal(Camera* _camera, GSvector2* _rotate);

	//�f�X�g���N�^
	~CameraWorkNormal() override;

	//�J�n����
	void start(void) override;

	//���s����
	void run(float _deltaTime) override;

private:
	//�X�e�B�b�N�̑���
	const GSvector2 velocity(void);

	//�{�^�����������Ƃ��ɃJ�����̈ʒu���v���C���[�̌��ɓ���������
	void resetCamera(void);

private:
	GSvector2* m_rotate;							//��]

	std::unique_ptr<CWParameterReader> m_parameter;	//�p�����[�^

	float m_speed_input;							//���͑��x

	float m_distance;								//����

	GSvector2 m_trackingSpeed;						//�J�����ƃ^�[�Q�b�g�̒ǔ����x

	float m_clamp_elevation;						//������]�͈̔�
};