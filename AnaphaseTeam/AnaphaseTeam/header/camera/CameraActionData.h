/*********************************************************************
@file	CameraActionData.h
@brief	カメラアクションデータ
@author Yuuho Aritomi
@date	2016/11/21
*********************************************************************/
#pragma once

#include <unordered_map>
#include <memory>

class Camera;
class CameraAction;
enum CameraActionID;

typedef std::shared_ptr<CameraAction> cameraAction_ptr;
typedef std::unordered_map<int, cameraAction_ptr> cameraAction_map;

class CameraActionData
{
public:
	/*****************************************************************
	@brief コンストラクタ
	*****************************************************************/
	CameraActionData();



	/*****************************************************************
	@brief デストラクタ
	*****************************************************************/
	~CameraActionData();



	/*****************************************************************
	@brief 読み込み
	@param[_id]		アクションID
	@param[_data]	データ
	*****************************************************************/
	void load(
		const CameraActionID&	_id, 
		CameraAction*			_date);



	/*****************************************************************
	@brief 実行
	@param[_id] アクションID
	*****************************************************************/
	void run(const CameraActionID& _id);

private:
	cameraAction_map m_cameraActions;
};

