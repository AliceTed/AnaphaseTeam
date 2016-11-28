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



	//更新処理
	void update(float _deltaTime);



	//描画処理
	void draw(void);

private:
	virtual void update_cameraWork(float _deltaTime);

	virtual void draw_cameraWork(void);

protected:
	Camera* m_camera;

	float m_deltaTime;
};