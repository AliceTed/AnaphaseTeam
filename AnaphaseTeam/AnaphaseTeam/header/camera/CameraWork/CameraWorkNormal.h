/*************************************************
@file	CameraWorkNormal.h
@brief	カメラワーク・ノーマル
@author Yuuho Aritomi
@date	2016/11/28
*************************************************/
#pragma once

#include <gslib.h>
#include "I_CameraWork.h"

class Camera;

class CameraWorkNormal : public I_CameraWork
{
public:
	/*********************************************
	@brief コンストラクタ
	*********************************************/
	CameraWorkNormal(Camera* _camera);



	/*********************************************
	@brief デストラクタ
	*********************************************/
	~CameraWorkNormal() override;



	/*********************************************
	@brief 実行
	*********************************************/
	void run(void) override;

private:
	const GSvector2 velocity(void);

private:
	Camera* m_camera;

	GSvector2 m_rotate;
};