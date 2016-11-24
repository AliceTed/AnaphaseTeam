/*********************************************************************
@file	CameraActionData.h
@brief	�J�����A�N�V�����f�[�^
@author Yuuho Aritomi
@date	2016/11/21
*********************************************************************/
#pragma once

#include <unordered_map>
#include <memory>
#include "CameraWorkID.h"

class Camera;
class ICameraWork;

typedef std::shared_ptr<ICameraWork> cameraWork_ptr;
typedef std::unordered_map<int, cameraWork_ptr> cameraWork_map;

class CameraWorkData
{
public:
	/*****************************************************************
	@brief �R���X�g���N�^
	*****************************************************************/
	CameraWorkData();



	/*****************************************************************
	@brief �f�X�g���N�^
	*****************************************************************/
	~CameraWorkData();



	/*****************************************************************
	@brief �ǂݍ���
	@param[_id]		�A�N�V����ID
	@param[_data]	�f�[�^
	*****************************************************************/
	void load(
		CameraWorkID	_id,
		ICameraWork*	_date);



	/*****************************************************************
	@brief ���s
	@param[_id] �A�N�V����ID
	*****************************************************************/
	void run(const CameraWorkID& _id);

private:
	cameraWork_map m_cameraWorks;
};

