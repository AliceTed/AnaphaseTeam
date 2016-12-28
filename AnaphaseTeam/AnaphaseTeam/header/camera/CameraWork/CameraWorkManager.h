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
#include <string>

class Camera;				//カメラ
class CameraWorkData;		//カメラデータ
class SplineAnimManager;	//スプライン曲線アニメーション

class CameraWorkManager
{
public:
	/**
	@brief コンストラクタ
	@param[_camera]		カメラ
	@param[_isLockOn]	めんどくせぇ
	*/
	CameraWorkManager(Camera* _camera, bool* _isLockOn);

	//デストラクタ
	~CameraWorkManager();

	/**
	@brief ロード
	*/
	void load(void);

	/**
	@brief カメラワークの切り替え
	*/
	void change_cameraWork(std::string _id);

	/** 
	@brief 実行
	@param[_deltaTime] １フレーム毎の秒数
	*/
	void run(float _deltaTime);

private:
	Camera*								m_camera;				//カメラ

	std::unique_ptr<CameraWorkData>		m_cameraData;			//カメラデータ

	std::shared_ptr<SplineAnimManager>	m_splineAnimManager;	//3z

	GSvector2							m_rotate;				//回転

	std::string							m_current_cameraWork;	//現在のカメラワーク

	bool*								m_isLockOn;				//めんどくせぇ
};