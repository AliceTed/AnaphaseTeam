/**
@file	CameraActionLockOn.h
@brief	ロックオン時のカメラ
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include "CameraWorkEmpty.h"

class CameraWorkLockOn : public CameraWorkEmpty
{
public:
	/**
	@brief コンストラクタ
	@param[_camera] カメラ
	@param[_rotate] 回転
	*/
	CameraWorkLockOn(Camera* _camera, GSvector2* _rotate);

	//デストラクタ
	~CameraWorkLockOn();

	//開始処理
	void start(void) override;

	//実行処理
	void run(float _deltaTime) override;

	//次のカメラワーク
	std::string nextCameraWork(void) override;

	//終了したか？
	bool isEnd(void) override;

private:
	//カメラの位置をプレイヤーと中点の対角線上になるように更新
	void update_toEleDir(const GSvector3& _vec, float _distance);

	//カメラの位置を右と左どちらにずらすか？
	void whichSide(const GSvector3& _player, const GSvector3& _target);

private:
	GSvector2*							m_rotate;					//回転

	std::unique_ptr<CWParameterReader>	m_parameter;				//パラメータ

	float								m_elevation;				//仰角

	float								m_distance;					//カメラと注視点の距離
	float								m_distance_lockOn;			//プレイヤーとエネミーの距離

	GSvector2							m_trackingSpeed;			//カメラとターゲットの追尾速度

	float								m_offset_value;				//オフセット値
	float								m_offset;					//オフセット値の格納用変数
};