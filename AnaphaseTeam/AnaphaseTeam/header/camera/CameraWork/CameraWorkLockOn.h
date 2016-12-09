/**
@file	CameraActionLockOn.h
@brief	���b�N�I�����̃J����
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include "_CameraWork.h"

class CameraWorkLockOn : public CameraWork
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera] �J����
	*/
	CameraWorkLockOn(Camera* _camera, GSvector2* _rotate);

	/**
	@brief �f�X�g���N�^
	*/
	~CameraWorkLockOn();

	//���s����
	void run(float _deltaTime) override;

private:
	//�J�����̈ʒu���v���C���[�ƒ��_�̑Ίp����ɂȂ�悤�ɍX�V
	void update_toEleDir(const GSvector3& _vec, float _distance);

	//�J�����̈ʒu���E�ƍ��ǂ���ɂ��炷���H
	void whichSide(const GSvector3& _player, const GSvector3& _target);

private:
	GSvector2*							m_rotate;					//��]

	std::unique_ptr<CWParameterReader>	m_parameter;				//�p�����[�^

	float								m_elevation;				//�p

	float								m_distance;					//�J�����ƒ����_�̋���
	float								m_distance_lockOn;			//�v���C���[�ƃG�l�~�[�̋���

	GSvector2							m_trackingSpeed;			//�J�����ƃ^�[�Q�b�g�̒ǔ����x

	float								m_offset_value;				//�I�t�Z�b�g�l
	float								m_offset;					//�I�t�Z�b�g�l�̊i�[�p�ϐ�
};