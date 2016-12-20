/**
@file I_CameraWork.h
@brief カメラワークインターフェイス
@author Yuuho Aritomi
@date 2016/11/24
*/
#pragma once

#include <gslib.h>
#include "E_CameraWorkID.h"

class I_CameraWork
{
public:
	//デストラクタ
	virtual ~I_CameraWork()
	{

	}

	/**
	@brief 開始処理
	*/
	virtual void start(void) = 0;

	/**
	@brief 実行処理
	@parma[_deltaTime] １フレーム毎の秒数
	*/
	virtual void run(float _deltaTime) = 0;

	/**
	@return 次のカメラワーク
	*/
	virtual E_CameraWorkID nextCameraWork(void) = 0;

	/**
	@return 終了しているか？
	*/
	virtual bool isEnd(void) = 0;
};