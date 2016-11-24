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
class ICameraWork;
enum CameraWorkID;

typedef std::shared_ptr<ICameraWork> cameraWork_ptr;
typedef std::unordered_map<int, cameraWork_ptr> cameraWork_map;

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
	void load(
		const CameraWorkID&	_id,
		ICameraWork*			_date);



	/*****************************************************************
	@brief 実行
	@param[_id] アクションID
	*****************************************************************/
	void run(const CameraWorkID& _id);

private:
	cameraWork_map m_cameraWorks;
};

