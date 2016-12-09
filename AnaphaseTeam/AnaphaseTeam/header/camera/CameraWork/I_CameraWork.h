/**
@file I_CameraWork.h
@brief カメラワークインターフェイス
@author Yuuho Aritomi
@date 2016/11/24
*/
#pragma once

#include <gslib.h>

class I_CameraWork
{
public:
	/**
	@brief デストラクタ
	*/
	virtual ~I_CameraWork()
	{

	}

	/**
	@brief[_deltaTime] １フレーム毎の秒数
	*/
	virtual void run(float _deltaTime) = 0;
};