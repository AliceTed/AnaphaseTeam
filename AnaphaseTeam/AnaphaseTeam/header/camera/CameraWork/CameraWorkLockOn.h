/****************************************************************
@file	CameraActionLockOn.h
@brief	ロックオン時のカメラ
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include "CameraWork.h"

class CameraWorkLockOn : public CameraWork
{
public:
	/************************************************************
	@brief コンストラクタ
	@param[_camera] カメラ
	************************************************************/
	CameraWorkLockOn(Camera* _camera);

	

	/************************************************************
	@brief デストラクタ
	************************************************************/
	~CameraWorkLockOn();

private:
	void update(void) override;
};