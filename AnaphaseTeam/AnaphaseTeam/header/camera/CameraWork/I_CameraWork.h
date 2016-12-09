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
	@brief 更新処理
	@param[_deltaTime] １フレーム毎の秒数
	*/
	virtual void update(float _deltaTime) = 0;



	/**
	@brief 描画処理
	*/
	virtual void draw(void) = 0;
};