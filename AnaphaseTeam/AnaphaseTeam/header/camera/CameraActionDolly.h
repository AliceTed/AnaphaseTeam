/**********************************************
@file	CameraActionDolly.h
@brief	カメラの移動撮影
@author Yuuho Aritomi
@date	2016/11/14
**********************************************/
#pragma once

#include "CameraWork/I_CameraWork.h"
#include <gslib.h>

class Camera;

class CameraActionDolly : public I_CameraWork
{
public:
	/******************************************
	@brief コンストラクタ
	@param[_camera]			カメラ
	@param[_target]			カメラターゲット
	@param[_elevation]		仰角
	@param[_direction]		方位角
	******************************************/
	CameraActionDolly(
		Camera*			_camera,
		GSvector3*		_target,
		float*			_elevation,
		float*			_direction);



	/******************************************
	@brief デストラクタ
	******************************************/
	virtual ~CameraActionDolly() override;



	/******************************************
	@brief 初期化
	@param[_distance]	距離
	******************************************/
	void initialize(const float _distance);



	/******************************************
	@brief 実行
	******************************************/
	void run(void) override;

protected:

private:
	Camera*		m_camera;			//カメラ
	GSvector3*	m_target;			//カメラターゲット
	float*		m_elevation;		//仰角
	float*		m_direction;		//方位角
	float		m_distance;			//**@brief 距離
};