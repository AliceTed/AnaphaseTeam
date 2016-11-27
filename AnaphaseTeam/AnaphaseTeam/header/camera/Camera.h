/******************************************************
@file	Camera.h
@brief	カメラ
@author Yuuoh Aritomi : Matuo
@date	2016/09/23 Ver1.00
******************************************************/
#pragma once

#include <gslib.h>
#include <memory>
//#include "Perspective.h"
#include "LookAt.h"

#include "../../header/transform/Transform.h"

typedef GSvector4 Perspective;

class CameraTarget;

class Camera
{

public:
	/**************************************************
	@brief コンストラクタ
	**************************************************/
	Camera(void);



	/**************************************************
	@brief デストラクタ
	**************************************************/
	~Camera();



	/**************************************************
	@brief 更新処理
	**************************************************/
	void update(void);



	/**************************************************
	@brief 指定した位置に移動する
	@param[_position] 位置
	**************************************************/
	void move(const GSvector3& _position);



	/**************************************************
	@brief カメラが見ている位置を設定する
	@param[_target] ターゲット
	**************************************************/
	void lookAt(const GSvector3& _target);



	/********************************************************
	@brief	ティルトカメラワーク
	x軸回転のみで被写体を見る
	（もっと簡単にしたいよ）
	@param[_position_camera]	カメラの位置
	@param[_position_target]	ターゲットの位置
	@param[_direction]			方位角
	@param[_followSpeed_camera] カメラの追尾速度
	@param[_followSpeed_target]	ターゲットの追尾速度
	[0] 追尾無し
	[0.1~0.9] ディレイありの追尾
	[1] 完全追尾
	********************************************************/
	void cameraWork_tilt(
		const GSvector3&	_position_camera,
		const GSvector3&	_position_target,
		const float			_direction,
		const float			_followSpeed_camera,
		const float			_followSpeed_target
	);
	
	
	
	/********************************************************
	@brief	ティルトカメラワーク
	x軸回転のみで被写体を見る
	（もっと簡単にしたいよ）
	@param[_position_camera]	カメラの位置
	@param[_position_target]	ターゲットの位置
	@param[_elevation]			仰角
	@param[_followSpeed_camera] カメラの追尾速度
	@param[_followSpeed_target]	ターゲットの追尾速度
	[0] 追尾無し
	[0.1~0.9] ディレイありの追尾
	[1] 完全追尾
	********************************************************/
	void cameraWork_pan(
		const GSvector3& _position_camera,
		const GSvector3& _position_target,
		const float _elevation,
		const float _followSpeed_camera,
		const float _followSpeed_target
	);



	/********************************************************
	@brief	カメラワーク・ドリー
	ターゲットに追従する
	@param[_position_target]	ターゲット位置
	@param[_elevation]			仰角
	@param[_direction]			方位角
	@param[_distance]			距離
	@param[_followSpeed_camera]	カメラの追尾速度
	@param[_followSpeed_target] ターゲットの追尾速度
	********************************************************/
	void cameraWork_dolly(
		const GSvector3&	_position_target,
		const float			_elevation,
		const float			_direction,
		const float			_distance,
		const float			_followSpeed_camera,
		const float			_followSpeed_target
	);



	/**************************************************
	@brief プレイヤーの位置を保持
	@param[_target] プレイヤーの位置を入れてね
	**************************************************/
	void lookAt_cameraTarget_player(const GSvector3& _target);



	/**************************************************
	@brief エネミーの位置を保持
	@param[_target] エネミーの位置を入れてくれ
	**************************************************/
	void lookAt_cameraTarget_enemy(const GSvector3& _target);



	/**************************************************
	@brief カメラがターゲットに追尾
	@param[_target] ターゲット
	@param[_speed]	速度
					[0] 追尾無し
					[1] ディレイありの追尾
					[2] 完全追尾
	**************************************************/
	void follow_position(const GSvector3& _target, const float _speed);



	/**************************************************
	@brief 注視点がターゲットに追尾
	@param[_target] ターゲット
	@param[_speed]	速度
	[0] 追尾無し
	[1] ディレイありの追尾
	[2] 完全追尾
	**************************************************/
	void follow_target(const GSvector3& _target, const float _speed);



	/*******************************************************
	@brief 拡大範囲を設定
	@param[_min] 最小値
	@param[_max] 最大値
	*******************************************************/
	void zoom_clamp(
		const float _min,
		const float _max
	);



	/*******************************************************
	@brief ズーム
	@param[_value] 値
	*******************************************************/
	void zoom(const float _value);



	/*******************************************************
	@brief ズームイン
	@param[_speed] 速度
	*******************************************************/
	void zoom_in(const float _speed);



	/*******************************************************
	@brief ズームアウト
	@param[_speed] 速度
	*******************************************************/
	void zoom_out(const float _speed);



	/**************************************************
	@return パースペクティブ
	**************************************************/
	const Perspective perspective(void) const
	{
		return m_perspective;
	}
	/**************************************************
	@return 位置
	**************************************************/
	const GSvector3 position(void) const
	{
		return m_lookAt.position();
	}
	/**************************************************
	@return ターゲット
	**************************************************/
	const GSvector3 target(void) const
	{
		return m_lookAt.target();
	}
	/**************************************************
	@return カメラターゲット（プレイヤー）
	**************************************************/
	const GSvector3& cameraTarget_player(void) const;
	/**************************************************
	@return カメラターゲット（エネミー）
	**************************************************/
	const GSvector3& cameraTarget_enemy(void) const;

	/**
	@author Matuo
	*/
	//void lookAt(const GSvector3& target, float dir);

	/**
	@author Matuo
	*/
	const bool isFrustumCulling(const GSvector3& center,float radius )const;

	/**
	@author Matuo
	*/
	const float nearDistance(const GSvector3& ohter,float radius)const;

	/**
	@author Matuo
	*/
	const float distance(const GSvector3& ohter)const;

	//取りあえず
	const Transform transform()const;

private:
	void update_perspective(void);

	void update_zoom(const float _speed);

private:
	//Perspective						m_perspective;
	Perspective						m_perspective;
	float							m_fov_min;
	float							m_fov_max;
	GSmatrix4						m_matProjection;
	LookAt							m_lookAt;
	std::shared_ptr<CameraTarget>	m_cameraTarget_player;
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;
};