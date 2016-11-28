/****************************************************************
@file	CameraActionLockOn.h
@brief	ロックオン時のカメラ
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include <gslib.h>
#include "_CameraWork.h"

class CameraWorkLockOn : public CameraWork
{
public:
	/************************************************************
	@brief コンストラクタ
	@param[_camera] カメラ
	************************************************************/
	CameraWorkLockOn(Camera* _camera, GSvector2* _rotate);

	

	/************************************************************
	@brief デストラクタ
	************************************************************/
	~CameraWorkLockOn();

private:
	void draw_cameraWork(void) override;

private:
	GSvector2* m_rotate;
};