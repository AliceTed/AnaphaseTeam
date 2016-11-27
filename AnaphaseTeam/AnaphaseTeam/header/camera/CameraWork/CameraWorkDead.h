/*********************************************************************
@file	CameraWorkDead.h
@brief	カメラワーク（死亡）
@author Yuuho Aritomi
@date	2016/11/21
*********************************************************************/
#pragma once

#include "CameraWork.h"

class CameraWorkDead : public CameraWork
{
public:
	/*****************************************************************
	@brief コンストラクタ
	@param[_camera] カメラ
	*****************************************************************/
	CameraWorkDead(Camera* _camera);



	/*****************************************************************
	@brief デストラクタ
	*****************************************************************/
	~CameraWorkDead() override;

private:
	void update(void) override;
};