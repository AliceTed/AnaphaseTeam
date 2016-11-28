/************************************************
@file I_CameraWork.h
@brief カメラワークインターフェイス
@author Yuuho Aritomi
@date 2016/11/24
************************************************/
#pragma once

#include <gslib.h>

class I_CameraWork
{
public:
	/********************************************
	@brief デストラクタ
	********************************************/
	virtual ~I_CameraWork()
	{

	}



	/********************************************
	@brief 実行
	********************************************/
	virtual void run(void) = 0;
};