/**
@file	CameraWorkDead.h
@brief	カメラワーク（死亡）
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include "CameraWorkEmpty.h"

class CameraWorkDead : public CameraWorkEmpty
{
public:
	/**
	@brief コンストラクタ
	@param[_camera] カメラ
	*/
	CameraWorkDead(Camera* _camera);

	/**
	@brief デストラクタ
	*/
	~CameraWorkDead() override;

	//開始処理
	void start(void) override;

	//実行処理
	void run(float _deltaTime) override;
};