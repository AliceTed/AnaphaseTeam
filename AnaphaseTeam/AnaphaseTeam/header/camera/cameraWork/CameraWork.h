/************************************************************************************
@file	CameraWork.h
@brief	汎用カメラワーククラス
@author Yuuho Aritomi
@date	2016/11/17
************************************************************************************/
#pragma once

#include <gslib.h>

class Camera;

class CameraWork
{
public:
	/********************************************************************************
	@brief コンストラクタ
	@param[_camera] カメラ
	********************************************************************************/
	CameraWork(Camera* _camera);



	/********************************************************************************
	@brief デストラクタ
	********************************************************************************/
	virtual ~CameraWork();



	/********************************************************************************
	@brief 初期化
	@param[_position]	位置
	@param[_target]		ターゲット
	********************************************************************************/
	void initialize(
		const GSvector3& _position,
		const GSvector3& _target
	);

	/********************************************************************************
	@brief 位置初期化
	@param[_x] x成分
	@param[_y] y成分
	@param[_z] z成分
	@return 初期化値
	********************************************************************************/
	const GSvector3& initialize_position(
		const float _x,
		const float _y,
		const float _z
	);

	/********************************************************************************
	@brief ターゲット初期化
	@param[_x] x成分
	@param[_y] y成分
	@param[_z] z成分
	@return 初期化値
	********************************************************************************/
	const GSvector3& initialize_target(
		const float _x,
		const float _y,
		const float _z
	);

	virtual void run() = 0;

protected:
	Camera* m_camera;		//カメラ
	
	GSvector3 m_position;	//位置
	GSvector3 m_target;		//ターゲット
};