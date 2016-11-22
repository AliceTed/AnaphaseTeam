/****************************************************************
@file	CameraActionLockOn.h
@brief	ロックオン時のカメラ
@author Yuuho Aritomi
@date	2016/11/21
****************************************************************/
#pragma once

#include "../CameraAction.h"

class Camera;

class CameraActionLockOn : public CameraAction
{
public:
	/************************************************************
	@brief コンストラクタ
	@param[_camera] カメラ
	************************************************************/
	CameraActionLockOn(Camera* _camera);

	

	/************************************************************
	@brief デストラクタ
	************************************************************/
	~CameraActionLockOn();



	/************************************************************
	@brief 実行
	************************************************************/
	void run(void) override;

private:
	Camera* m_camera;
};