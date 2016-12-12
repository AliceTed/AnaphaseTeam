/**
@file CameraWorkTest.h
@brief カメラワークテスト
@author Yuuho Aritomi
@date 2016/12/12
*/
#pragma once

#include "CameraWorkEmpty.h"

class CameraWorkTest : public CameraWorkEmpty
{
public:
	/**
	@brief コンストラクタ
	@param[_camera] カメラ
	*/
	CameraWorkTest(Camera* _camera);

	//デストラクタ
	~CameraWorkTest() override;

	//開始処理
	void start(void) override;

	//実行処理
	void run(float _deltaTime) override;
};