/**
@file	CameraWork.h
@brief	カメラワーク
@author Yuuho Aritomi
@date	2016/11/28
*/
#pragma once

#include <gslib.h>
#include <memory>
#include "I_CameraWork.h"

class Camera;				//カメラ
class CWParameterReader;	//カメラワーク・パラメータ読み込み機

class CameraWorkEmpty : public I_CameraWork
{
public:
	/**
	@brief コンストラクタ
	*/
	CameraWorkEmpty(Camera* _camera);

	/**
	@brief デストラクタ
	*/
	~CameraWorkEmpty() override;

	//開始処理
	virtual void start(void) override;

	//実行処理
	virtual void run(float _deltaTime) override;

protected:
	Camera*								m_camera;			//カメラ

	std::unique_ptr<CWParameterReader>	m_paramater_def;	//カメラの定数パラメータ

	GSvector3							m_offset_target;	//ターゲットオフセット
};