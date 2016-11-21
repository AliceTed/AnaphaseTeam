/*********************************************************************
@file	CameraActionData.h
@brief	�J�����A�N�V�����f�[�^
@author Yuuho Aritomi
@date	2016/11/21
*********************************************************************/
#pragma once

#include <unordered_map>
#include <memory>

class Camera;
class CameraAction;
enum CameraActionID;

typedef std::shared_ptr<CameraAction> cameraAction_ptr;
typedef std::unordered_map<int, cameraAction_ptr> cameraAction_map;

class CameraActionData
{
public:
	/*****************************************************************
	@brief �R���X�g���N�^
	*****************************************************************/
	CameraActionData();



	/*****************************************************************
	@brief �f�X�g���N�^
	*****************************************************************/
	~CameraActionData();



	/*****************************************************************
	@brief �ǂݍ���
	@param[_id]		�A�N�V����ID
	@param[_data]	�f�[�^
	*****************************************************************/
	void load(
		const CameraActionID&	_id, 
		CameraAction*			_date);



	/*****************************************************************
	@brief ���s
	@param[_id] �A�N�V����ID
	*****************************************************************/
	void run(const CameraActionID& _id);

private:
	cameraAction_map m_cameraActions;
};

