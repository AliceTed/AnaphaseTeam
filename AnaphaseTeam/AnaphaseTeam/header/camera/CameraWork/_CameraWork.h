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

class CameraWork : public I_CameraWork
{
public:
	/**
	@brief コンストラクタ
	*/
	CameraWork(Camera* _camera);



	/**
	@brief デストラクタ
	*/
	~CameraWork() override;



	//更新処理
	void update(float _deltaTime);



	//描画処理
	void draw(void);

private:
	//カメラワーク更新処理
	virtual void update_cameraWork(float _deltaTime);

	//カメラワーク描画処理
	virtual void draw_cameraWork(void);

protected:
	Camera*								m_camera;			//カメラ

	std::unique_ptr<CWParameterReader>	m_paramater_def;	//カメラの定数パラメータ

	GSvector3							m_offset_target;	//ターゲットオフセット
};