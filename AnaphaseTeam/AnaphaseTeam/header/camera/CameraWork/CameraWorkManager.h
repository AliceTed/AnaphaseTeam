/**
@file	CameraActionManager.h
@brief	�J�����A�N�V�����}�l�[�W���[
@author Yuuho Aritomi
@date	2016/11/14
*/
#pragma once

#include <unordered_map>
#include <memory>
#include <gslib.h>
#include <string>

class Camera;				//�J����
class CameraWorkData;		//�J�����f�[�^
class SplineAnimManager;	//�X�v���C���Ȑ��A�j���[�V����

class CameraWorkManager
{
public:
	/**
	@brief �R���X�g���N�^
	@param[_camera]		�J����
	@param[_isLockOn]	�߂�ǂ�����
	*/
	CameraWorkManager(Camera* _camera, bool* _isLockOn);

	//�f�X�g���N�^
	~CameraWorkManager();

	/**
	@brief ���[�h
	*/
	void load(void);

	/**
	@brief �J�������[�N�̐؂�ւ�
	*/
	void change_cameraWork(std::string _id);

	/** 
	@brief ���s
	@param[_deltaTime] �P�t���[�����̕b��
	*/
	void run(float _deltaTime);

private:
	Camera*								m_camera;				//�J����

	std::unique_ptr<CameraWorkData>		m_cameraData;			//�J�����f�[�^

	std::shared_ptr<SplineAnimManager>	m_splineAnimManager;	//3z

	GSvector2							m_rotate;				//��]

	std::string							m_current_cameraWork;	//���݂̃J�������[�N

	bool*								m_isLockOn;				//�߂�ǂ�����
};