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
class Timer;

class CameraWorkNormal : public CameraWorkEmpty
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
	@param[_camera] �J����
	@param[_rotate] ��]
	*/
	CameraWorkNormal(Camera* _camera, GSvector2* _rotate);
	//�f�X�g���N�^
	~CameraWorkNormal() override;
	/**
	@fn
	@brief ������
	*/
	void init();
	//�J�n����
	void start(void) override;
	//���s����
	void run(float _deltaTime) override;
	//���̃J�������[�N
	std::string nextCameraWork(void);
	//�I���������H
	bool isEnd(void);
private:
	//�����œ�������
	void autoMove(float _deltaTime);
	//�{�^�����������Ƃ��ɃJ�����̈ʒu���v���C���[�̌��ɓ���������
	void resetCamera(void);
	//�J�����𓮂�������
	void move();
	//�X�e�B�b�N�̑���
	const GSvector2 velocity(void);
private:
	//��]
	GSvector2* m_rotate;							
	//�p�����[�^
	std::unique_ptr<CWParameterReader> m_parameter;	
	//���͑��x
	float m_speed_input;							
	//����
	float m_distance;								
	//�J�����ƃ^�[�Q�b�g�̒ǔ����x
	GSvector2 m_trackingSpeed;			
	//�^�C�}�[
	std::unique_ptr<Timer> m_timer;
};