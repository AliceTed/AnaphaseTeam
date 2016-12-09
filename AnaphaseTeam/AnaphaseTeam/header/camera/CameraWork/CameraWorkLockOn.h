/**
@file	CameraActionLockOn.h
@brief	ロックオン時のカメラ
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include "_CameraWork.h"

class CameraWorkLockOn : public CameraWork
{
public:
	/**
	@brief コンストラクタ
	@param[_camera] カメラ
	*/
	CameraWorkLockOn(Camera* _camera, GSvector2* _rotate);

	/**
	@brief デストラクタ
	*/
	~CameraWorkLockOn();

	//実行処理
	void run(float _deltaTime) override;

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