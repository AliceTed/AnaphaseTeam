/****************************************************
@file	CameraWork.h
@brief	カメラワーク
@author Yuuho Aritomi
@date	2016/11/28
****************************************************/
#pragma once

#include "I_CameraWork.h"

class Camera;

class CameraWork : public I_CameraWork
{
public:
	/************************************************
	@brief コンストラクタ
	************************************************/
	CameraWork(Camera* _camera);



	/************************************************
	@brief デストラクタ
	************************************************/
	~CameraWork() override;



	/************************************************
	@brief 実行
	************************************************/
	void run(void) override;

private:
	virtual void update(void);

protected:
	Camera* m_camera;
};