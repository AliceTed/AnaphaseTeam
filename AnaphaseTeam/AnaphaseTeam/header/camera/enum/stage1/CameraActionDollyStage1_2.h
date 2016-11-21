/***************************************************************
@file	CameraActionDollyStage1_2.h
@brief	�X�e�[�W�P�p�h���[�J�����@���̂Q
@author	Yuuho Aritomi
@date	2016/11/14
***************************************************************/
#pragma once

#include "../../CameraActionDolly.h"

class CameraActionDollyStage1_2 : public CameraActionDolly
{
public:
	/***********************************************************
	@brief					�R���X�g���N�^
	@param[_camera]			�J����
	@param[_cameraTarget]	�J�����^�[�Q�b�g
	@param[_input]			�C���v�b�g
	***********************************************************/
	CameraActionDollyStage1_2(
		Camera*		_camera,
		GSvector3*	_target,
		float*		_elevation,
		float*		_direction);

	/***********************************************************
	@brief �f�X�g���N�^
	***********************************************************/
	~CameraActionDollyStage1_2() override;
};