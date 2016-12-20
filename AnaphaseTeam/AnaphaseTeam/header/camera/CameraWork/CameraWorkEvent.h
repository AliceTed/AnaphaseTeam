/**
@file CameraWorkEvent.h
@brief カメラワーク・イベント
@author Yuuho Aritomi
@date 2016/12/19
*/
#pragma once

#include <memory>
#include "CameraWorkEmpty.h"
#include"../../spline/SPLINE_ANIMATION_ID.h"

class SplineAnimManager;

class CameraWorkEvent : public CameraWorkEmpty
{
public:
	/**
	@brief コンストラクタ
	@param[_camera] カメラ
	*/
	CameraWorkEvent(Camera* _camera, SplineAnimManager* _splineAnimManager);

	//デストラクタ
	~CameraWorkEvent();

	//開始処理
	void start(void) override;

	//実行処理
	void run(float _deltaTime) override;

private:
	SplineAnimManager* m_splineAnimManager;
};