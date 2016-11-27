/*************************************************
@file	CameraWorkNormal.h
@brief	カメラワーク・ノーマル
@author Yuuho Aritomi
@date	2016/11/28
*************************************************/
#pragma once

#include <gslib.h>
#include "CameraWork.h"

class CameraWorkNormal : public CameraWork
{
public:
	/*********************************************
	@brief コンストラクタ
	*********************************************/
	CameraWorkNormal(Camera* _camera, GSvector2* _rotate);



	/*********************************************
	@brief デストラクタ
	*********************************************/
	~CameraWorkNormal() override;

private:
	void update(void) override;

	const GSvector2 velocity(void);

private:
	GSvector2* m_rotate;
};