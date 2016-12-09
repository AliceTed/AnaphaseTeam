/**
@file	CameraActionData.h
@brief	�J�����A�N�V�����f�[�^
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include <unordered_map>
#include <memory>
#include "E_CameraWorkID.h"

class Camera;
class I_CameraWork;

class CameraWorkData
{
public:
	/**
	@brief �R���X�g���N�^
	*/
	CameraWorkData();

	/**
	@brief �f�X�g���N�^
	*/
	~CameraWorkData();

	/**
	@brief �ǂݍ���
	@param[_id]		�A�N�V����ID
	@param[_data]	�f�[�^
	*/
	void add(
		E_CameraWorkID	_id,
		I_CameraWork*	_data
	);

	/**
	@brief ���s
	@param[_id] �A�N�V����ID
	*/
	I_CameraWork* get(const E_CameraWorkID _id);

private:
	using CameraWork_Ptr = std::shared_ptr<I_CameraWork>;						//�������������̂��߂�ǂ������̂�
	using CameraWork_Map = std::unordered_map<E_CameraWorkID, CameraWork_Ptr>;	//�������������̂��߂�ǂ������̂�

	CameraWork_Map m_cameraWorks;												//�J�������[�N
};

