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
class CameraAction;
class CameraActionData;

enum CameraActionID;

class CameraActionManager
{
public:
	/*****************************************
	@brief コンストラクタ
	@param[_camera]			カメラ
	@param[_cameraTarget]	カメラターゲット
	@param[_input]			インプット
	*****************************************/
	CameraActionManager(Camera* _camera);



	/*****************************************
	@brief デストラクタ
	*****************************************/
	~CameraActionManager();



	/*****************************************
	@brief ロード
	*****************************************/
	void load(void);



	/*****************************************
	@brief カメラワークの切り替え
	*****************************************/
	void change_cameraWork(const CameraActionID& _id);



	/*****************************************
	@brief 実行
	*****************************************/
	void run(void);

private:
	Camera*				m_camera;
	std::unique_ptr<CameraActionData> m_cameraData;
	CameraActionID		m_current_cameraAction;
};