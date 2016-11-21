/************************************************************
@file	CameraActionDollyStage1_1.h
@brief	ステージ１用ドリーカメラ　その１
@author Yuuho Aritomi
@date	2016/11/14
************************************************************/
#pragma once

#include "../../CameraActionDolly.h"

class CameraActionDollyStage1_1 : public CameraActionDolly
{
public:
	/********************************************************
	@brief					コンストラクタ
	@param[_camera]			カメラ
	@param[_cameraTarget]	カメラターゲット
	@param[_input]			インプット
	********************************************************/
	CameraActionDollyStage1_1(
		Camera*			_camera, 
		GSvector3*		_target, 
		float*			_elevation,
		float*			_direction);



	/********************************************************
	@brief デストラクタ
	********************************************************/
	~CameraActionDollyStage1_1() override;
};