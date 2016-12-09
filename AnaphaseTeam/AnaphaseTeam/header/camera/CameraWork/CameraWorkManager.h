/**
@file	CameraActionManager.h
@brief	カメラアクションマネージャー
@author Yuuho Aritomi
@date	2016/11/14
*/
#pragma once

#include <unordered_map>
#include <memory>
#include <gslib.h>
#include "E_CameraWorkID.h"

class Camera;				//カメラ
class CameraWorkData;		//カメラデータ

class CameraWorkManager
{
public:
	/**
	@brief コンストラクタ
	@param[_camera]			カメラ
	@param[_cameraTarget]	カメラターゲット
	@param[_input]			インプット
	*/
	CameraWorkManager(Camera* _camera);

	/**
	@brief デストラクタ
	**/
	~CameraWorkManager();

	/**
	@brief ロード
	*/
	void load(void);

	/**
	@brief カメラワークの切り替え
	*/
	void change_cameraWork(const E_CameraWorkID _id);

	/** 
	@brief 実行
	@param[_deltaTime] １フレーム毎の秒数
	*/
	void run(float _deltaTime);

private:
	Camera*							m_camera;				//カメラ

	std::unique_ptr<CameraWorkData> m_cameraData;			//カメラデータ

	GSvector2						m_rotate;				//回転

	E_CameraWorkID					m_current_cameraWork;	//現在のカメラワーク
};