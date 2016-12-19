/**
@file	Controller.h
@brief	�J�����𑀍삷��
@author Yuho Artiomi
@date	2016-08-28 Ver1.00
*/
#pragma once

#include <gslib.h>
#include <memory>

#include "CameraWork\E_CameraWorkID.h"

class	Map;
class	Camera;
class	CameraWorkManager;
class	IRenderer;
enum	CameraWorkID;

class CameraController
{

public:
	/**
	@brief �f�t�H���g�R���X�g���N�^
	@param[_camera] ���삷��J����
	*/
	CameraController();

	//�f�X�g���N�^
	~CameraController();

	/**
	@brief �X�V����
	@param[_deltaTime] �P�t���[�����̕b��
	*/
	void update(float _deltaTime);

	/**
	@brief �`�揈��
	*/
	void draw(IRenderer* _renderer);



	/**
	@brief �n�ʂƂ̂����蔻��
	@param[_map]
	*/
	void collisionGround(const Map& _map);

	/**
	@brief �J�������[�N�̏�Ԃ�؂�ւ���
	@param[_id] �J�������[�N�h�c
	*/
	void change_cameraWork(const E_CameraWorkID _id);

	/**
	@return �J����
	*/
	Camera* get_camera(void);

	/**
	@brief �{���ɂ߂�ǂ������i���̂��������ǁj
	@param[_isLockOn] 
	*/
	void set_isLockOn(bool _isLockOn);

private:
	std::shared_ptr<Camera> m_camera;						//�J����

	std::shared_ptr<CameraWorkManager> m_cameraWorkManager;	//�J�������[�N�E�}�l�[�W���[

	float m_deltaTime;										//�P�t���[�����̕b��

	bool m_isLockOn;										//�߂�ǂ�����
};