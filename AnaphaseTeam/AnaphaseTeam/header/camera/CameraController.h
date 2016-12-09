/**
@file	Controller.h
@brief	カメラを操作する
@author Yuho Artiomi
@date	2016-08-28 Ver1.00
*/
#pragma once

#include <gslib.h>
#include <memory>

#include "CameraWork\E_CameraWorkID.h"

class	Camera;
class	CameraWorkManager;
enum	CameraWorkID;

class CameraController
{

public:
	/**
	@brief デフォルトコンストラクタ
	@param[_camera] 操作するカメラ
	*/
	CameraController(Camera* _camera);

	//デストラクタ
	~CameraController();

	/**
	@brief 更新処理
	@param[_deltaTime] １フレーム毎の秒数
	*/
	void update(float _deltaTime);

	/**
	@brief 描画処理
	*/
	void draw(void);

	/**
	@brief カメラワークの状態を切り替える
	@param[_id] カメラワークＩＤ
	*/
	void change_cameraWork(const E_CameraWorkID _id);

private:
	std::shared_ptr<CameraWorkManager> m_cameraWorkManager;	//カメラワーク・マネージャー 

	float m_deltaTime;										//１フレーム毎の秒数
};