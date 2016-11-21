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
class CameraActionDolly;

typedef std::shared_ptr<CameraAction> cameraAction_ptr;
typedef std::unordered_map<int, cameraAction_ptr> cameraAction_map;

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
	void run(void);

private:
	Camera*				m_camera;
	cameraAction_map	m_cameraActions;

	float m_elevation;
	float m_direction;
};