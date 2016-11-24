/****************************************************
@file	Controller.h
@brief	カメラを操作する
@author Yuho Artiomi
@date	2016-08-28 Ver1.00
****************************************************/

#pragma once

#include <gslib.h>
#include <memory>

class	Camera;
class	CameraWorkManager;
enum	CameraWorkID;

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
	@brief 更新処理
	***********************************************/
	void update(void);



	/***********************************************
	@brief 操作するカメラの変更
	@param[_camera] 操作するカメラ
	***********************************************/
	void change_control(Camera* _camera);



	/***********************************************
	@brief カメラワークの変更
	***********************************************/
	void change_cameraWork(const CameraWorkID& _id);

private:
	Camera *m_camera;		// 動かしたいカメラ
	float m_distance;		// ターゲットとの距離
	float m_pitch;			// ピッチ
	float m_yow;			// ヨー

	std::shared_ptr<CameraWorkManager> m_cameraWorkManager;
};