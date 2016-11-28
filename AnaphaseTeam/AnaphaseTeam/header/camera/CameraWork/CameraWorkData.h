/*********************************************************************
@file	CameraActionData.h
@brief	カメラアクションデータ
@author Yuuho Aritomi
@date	2016/11/21
*********************************************************************/
#pragma once

#include <unordered_map>
#include <memory>
#include "E_CameraWorkID.h"

class Camera;
class I_CameraWork;

typedef std::shared_ptr<I_CameraWork> CameraWork_Ptr;
typedef std::unordered_map<int, CameraWork_Ptr> CameraWork_Map;

class CameraWorkData
{
public:
	/*****************************************************************
	@brief コンストラクタ
	*****************************************************************/
	CameraWorkData();



	/*****************************************************************
	@brief デストラクタ
	*****************************************************************/
	~CameraWorkData();



	/*****************************************************************
	@brief 読み込み
	@param[_id]		アクションID
	@param[_data]	データ
	*****************************************************************/
	void add(
		const E_CameraWorkID	_id,
		I_CameraWork*	_data
	);



	/*****************************************************************
	@brief 実行
	@param[_id] アクションID
	*****************************************************************/
	I_CameraWork* get(const E_CameraWorkID _id);

private:
	CameraWork_Map m_cameraWorks;
};

