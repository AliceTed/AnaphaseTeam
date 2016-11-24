/*********************************************
@file	CameraActionManager.h
@brief	カメラアクションマネージャー
@author Yuuho Aritomi
@date	2016/11/14
*********************************************/
#pragma once

#include <unordered_map>
#include <memory>

class Camera;
class CameraWorkData;

enum CameraWorkID;

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
	void change_cameraWork(const CameraWorkID& _id);



	/*****************************************
	@brief 実行
	*****************************************/
	void run(void);

private:
	Camera*				m_camera;
	std::unique_ptr<CameraWorkData> m_cameraData;
	CameraWorkID		m_current_cameraAction;
};