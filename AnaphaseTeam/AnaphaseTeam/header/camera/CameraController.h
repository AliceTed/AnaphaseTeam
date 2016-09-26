/**
@file 
Controller.h
@brief カメラを操作する
@author Yuho Artiomi
@date 2016-08-28 Ver1.00
*/

#pragma once

#include <gslib.h>

class Camera;

class CameraController
{
	Camera *m_camera;		// 動かしたいカメラ
	float m_distance;		// ターゲットとの距離
	float m_pitch;			// ピッチ
	float m_yow;			// ヨー

public:
	/**
	@brief デフォルトコンストラクタ
	@param[_camera] 操作するカメラ
	*/
	CameraController(Camera* _camera);

	/**
	@brief コンストラクタ
	*/
	CameraController(Camera* _camera, const float _distance, const float _pitch, const float _yow);

	/**
	@brief 操作するカメラの変更
	@param[_camera] 操作するカメラ
	*/
	void change_control(Camera* _camera);

	/**
	@brief 指定したターゲットを追尾する
	@param[_speed]	
	[0~1]の範囲で指定
	0の場合			:追尾が働かない
	0と1以外の場合	:ディレイの付与された追尾
	1の場合			:ディレイの付与されない追尾
	*/
	void follow(const GSvector3* _target, const float _speed);

	/**
	@brief 巨大な敵と戦う時用
	@param[_Target2] ここに巨大な敵のベクターを渡して
	*/
	void special_move1(GSvector3* _target1, GSvector3* _target2, float _pitch, float _distance);

	/**
	@brief 現在のカメラの向きを返す
	*/
	const float DIRECTION(void) const;
};