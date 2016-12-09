/**
@file	CameraWorkNormal.h
@brief	カメラワーク・ノーマル
@author Yuuho Aritomi
@date	2016/11/28
*/
#pragma once

#include <memory>
#include "_CameraWork.h"

class CWParameterReader;	//カメラワークのパラメータの読み込み機

class CameraWorkNormal : public CameraWork
{
public:
	/**
	@brief コンストラクタ
	*/
	CameraWorkNormal(Camera* _camera, GSvector2* _rotate);

	/**
	@brief デストラクタ
	*/
	~CameraWorkNormal() override;

private:
	//カメラワークの描画処理
	void draw_cameraWork(void) override;

	//スティックの操作
	const GSvector2 velocity(void);

private:
	GSvector2* m_rotate;							//回転

	std::unique_ptr<CWParameterReader> m_parameter;	//パラメータ

	float m_speed_input;							//入力速度
	float m_distance;								//距離
	GSvector2 m_trackingSpeed;						//カメラとターゲットの追尾速度
};