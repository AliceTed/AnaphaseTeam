/**
@file	CameraActionData.h
@brief	�J�����A�N�V�����f�[�^
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class Camera;
class I_CameraWork;

class CameraWorkData
{
public:
	//�R���X�g���N�^
	CameraWorkData();

	//�f�X�g���N�^
	~CameraWorkData();

	/**
	@brief �ǂݍ���
	@param[_id]		�A�N�V����ID
	@param[_data]	�f�[�^
	*/
	void add(
		std::string	_id,
		I_CameraWork*	_data
	);

	/**
	@brief ���s
	@param[_id] �A�N�V����ID
	*/
	I_CameraWork* get(std::string _id);

private:
	using CameraWork_Ptr = std::shared_ptr<I_CameraWork>;						//�������������̂��߂�ǂ������̂�
	using CameraWork_Map = std::unordered_map<std::string, CameraWork_Ptr>;	//�������������̂��߂�ǂ������̂�

	CameraWork_Map m_cameraWorks;												//�J�������[�N
};

