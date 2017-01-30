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
class Timer;

class CameraWorkNormal : public CameraWorkEmpty
{
public:
	/**
	@fn
	@brief コンストラクタ
	@param[_camera] カメラ
	@param[_rotate] 回転
	*/
	CameraWorkNormal(Camera* _camera, GSvector2* _rotate);
	//デストラクタ
	~CameraWorkNormal() override;
	/**
	@fn
	@brief 初期化
	*/
	void init();
	//開始処理
	void start(void) override;
	//実行処理
	void run(float _deltaTime) override;
	//次のカメラワーク
	std::string nextCameraWork(void);
	//終了したか？
	bool isEnd(void);
private:
	//自動で動く処理
	void autoMove(float _deltaTime);
	//ボタンを押したときにカメラの位置をプレイヤーの後ろに動かす処理
	void resetCamera(void);
	//カメラを動かす処理
	void move();
	//スティックの操作
	const GSvector2 velocity(void);
private:
	//回転
	GSvector2* m_rotate;							
	//パラメータ
	std::unique_ptr<CWParameterReader> m_parameter;	
	//入力速度
	float m_speed_input;							
	//距離
	float m_distance;								
	//カメラとターゲットの追尾速度
	GSvector2 m_trackingSpeed;			
	//タイマー
	std::unique_ptr<Timer> m_timer;
};