/****************************************************
@file	Controller.h
@brief	カメラを操作する
@author Yuho Artiomi
@date	2016-08-28 Ver1.00
****************************************************/

#pragma once

#include <gslib.h>
#include <memory>

class Camera;
class CameraActionManager;

class CameraController
{

public:
	/***********************************************
	@brief デフォルトコンストラクタ
	@param[_camera] 操作するカメラ
	***********************************************/
	CameraController(Camera* _camera);



	/***********************************************
	@brief コンストラクタ
	@param[_camera]		カメラ
	@param[_distance]	距離
	@param[_elevation]	仰角
	@param[_direction]	方位角
	***********************************************/
	CameraController(
		Camera* _camera, 
		const float _distance, 
		const float _elevation, 
		const float _direction
	);



	/***********************************************
	@brief 操作するカメラの変更
	@param[_camera] 操作するカメラ
	***********************************************/
	void change_control(Camera* _camera);



	/***********************************************
	@brief 巨大な敵と戦う時用
	@param[_target1] ここはプレイヤーー？
	@param[_Target2] ここに巨大な敵のベクターを渡して
	***********************************************/
	void special_move1(
		GSvector3* _target1, 
		GSvector3* _target2, 
		float _elevation, 
		float _distance
	);



	/***********************************************
	@return 方位角
	***********************************************/
	const float direction(void) const;

private:
	Camera *m_camera;		// 動かしたいカメラ
	float m_distance;		// ターゲットとの距離
	float m_pitch;			// ピッチ
	float m_yow;			// ヨー

	std::shared_ptr<CameraActionManager> m_cameraActionManager;
};