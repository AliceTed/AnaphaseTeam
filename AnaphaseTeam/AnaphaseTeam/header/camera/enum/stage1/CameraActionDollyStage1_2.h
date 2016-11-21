/***************************************************************
@file	CameraActionDollyStage1_2.h
@brief	ステージ１用ドリーカメラ　その２
@author	Yuuho Aritomi
@date	2016/11/14
***************************************************************/
#pragma once

#include "../../CameraActionDolly.h"

class CameraActionDollyStage1_2 : public CameraActionDolly
{
public:
	/***********************************************************
	@brief					コンストラクタ
	@param[_camera]			カメラ
	@param[_cameraTarget]	カメラターゲット
	@param[_input]			インプット
	***********************************************************/
	CameraActionDollyStage1_2(
		Camera*		_camera,
		GSvector3*	_target,
		float*		_elevation,
		float*		_direction);

	/***********************************************************
	@brief デストラクタ
	***********************************************************/
	~CameraActionDollyStage1_2() override;
};