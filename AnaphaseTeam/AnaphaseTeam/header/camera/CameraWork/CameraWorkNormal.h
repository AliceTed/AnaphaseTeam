/**
@file	CameraWorkNormal.h
@brief	カメラワーク・ノーマル
@author Yuuho Aritomi
@date	2016/11/28
*/
#pragma once

#include <memory>
#include "CameraWorkEmpty.h"

class CWParameterReader;	//カメラワークのパラメータの読み込み機

class CameraWorkNormal : public CameraWorkEmpty
{
public:
	/**
	@brief コンストラクタ
	@param[_camera] カメラ
	@param[_rotate] 回転
	*/
	CameraWorkNormal(Camera* _camera, GSvector2* _rotate);

	//デストラクタ
	~CameraWorkNormal() override;

	//開始処理
	void start(void) override;

	//実行処理
	void run(float _deltaTime) override;

private:
	//スティックの操作
	const GSvector2 velocity(void);

	//ボタンを押したときにカメラの位置をプレイヤーの後ろに動かす処理
	void resetCamera(void);

private:
	GSvector2* m_rotate;							//回転

	std::unique_ptr<CWParameterReader> m_parameter;	//パラメータ

	float m_speed_input;							//入力速度

	float m_distance;								//距離

	GSvector2 m_trackingSpeed;						//カメラとターゲットの追尾速度

	float m_clamp_elevation;						//ｘ軸回転の範囲
};