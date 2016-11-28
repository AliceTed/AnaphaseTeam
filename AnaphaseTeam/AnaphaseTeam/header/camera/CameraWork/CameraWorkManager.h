/*********************************************
@file	CameraActionManager.h
@brief	カメラアクションマネージャー
@author Yuuho Aritomi
@date	2016/11/14
*********************************************/
#pragma once

#include <unordered_map>
#include <memory>
#include <gslib.h>
#include "E_CameraWorkID.h"

class Camera;
class CameraWorkData;

class CameraWorkManager
{
public:
	/*****************************************
	@brief コンストラクタ
	@param[_camera]			カメラ
	@param[_cameraTarget]	カメラターゲット
	@param[_input]			インプット
	*****************************************/
	CameraWorkManager(Camera* _camera);



	/*****************************************
	@brief デストラクタ
	*****************************************/
	~CameraWorkManager();



	/*****************************************
	@brief ロード
	*****************************************/
	void load(void);



	/*****************************************
	@brief カメラワークの切り替え
	*****************************************/
	void change_cameraWork(const E_CameraWorkID _id);



	/*****************************************
	@brief 更新処理
	@param[_deltaTime]
	*****************************************/
	void update(float _deltaTime);



	/*****************************************
	@brief 描画
	*****************************************/
	void draw(void);

private:
	Camera*							m_camera;

	std::unique_ptr<CameraWorkData> m_cameraData;

	GSvector2						m_rotate;

	E_CameraWorkID					m_current_cameraWork;
};