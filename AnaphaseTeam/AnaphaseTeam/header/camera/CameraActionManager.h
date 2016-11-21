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
	ロード
	*****************************************/
	void load(void);



	/*****************************************
	@brief 実行
	*****************************************/
	void run(const CameraActionID& _id);

private:
	Camera*				m_camera;
	std::unique_ptr<CameraActionData> m_cameraData;
};