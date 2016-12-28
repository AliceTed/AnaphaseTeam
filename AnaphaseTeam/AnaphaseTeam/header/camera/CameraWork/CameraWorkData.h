/**
@file	CameraActionData.h
@brief	カメラアクションデータ
@author Yuuho Aritomi
@date	2016/11/21
*/
#pragma once

#include <string>
#include <unordered_map>
#include <memory>

class Camera;
class I_CameraWork;

class CameraWorkData
{
public:
	//コンストラクタ
	CameraWorkData();

	//デストラクタ
	~CameraWorkData();

	/**
	@brief 読み込み
	@param[_id]		アクションID
	@param[_data]	データ
	*/
	void add(
		std::string	_id,
		I_CameraWork*	_data
	);

	/**
	@brief 実行
	@param[_id] アクションID
	*/
	I_CameraWork* get(std::string _id);

private:
	using CameraWork_Ptr = std::shared_ptr<I_CameraWork>;						//いちいち書くのがめんどくさいので
	using CameraWork_Map = std::unordered_map<std::string, CameraWork_Ptr>;	//いちいち書くのがめんどくさいので

	CameraWork_Map m_cameraWorks;												//カメラワーク
};

