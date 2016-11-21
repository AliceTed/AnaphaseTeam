/*****************************************************************************
@file FixCamera.h
@brief	固定カメラワーク
@author Yuuho Aritomi
@date	2016/11/15
*****************************************************************************/
#pragma once

#include "CameraWork.h"

class FixCamera : public CameraWork
{
public:
	/*************************************************************************
	@brief コンストラクタ
	@param[_camera]		カメラ
	*************************************************************************/
	FixCamera(Camera* _camera);



	/*************************************************************************
	@brief デストラクタ
	*************************************************************************/
	~FixCamera() override;



	/*************************************************************************
	@brief 実行
	*************************************************************************/
	void run(void) override;

};