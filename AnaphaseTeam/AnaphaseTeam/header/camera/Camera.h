/******************************************************
@file .h
@brief カメラ
@author Yuuoh Aritomi : Matuo
@date 2016/09/23 Ver1.00
******************************************************/
#pragma once

#include <gslib.h>
#include <memory>
#include "Perspective.h"
#include "LookAt.h"

#include "../../header/transform/Transform.h"

class CameraTarget;

class Camera
{

public:
	/**************************************************
	@brief コンストラクタ
	**************************************************/
	Camera(void);



	/**************************************************
	@brief コンストラクタ
	@param[_perspective]	パースペクティブ
	@param[_position]		位置
	**************************************************/
	Camera(
		const Perspective&	_perspective, 
		const GSvector3&	_position
	);



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



	/**************************************************
	@brief ｘ軸回転のみで被写体を見る
	@param[_target] ターゲット
	@param[_direction] 方位角
	**************************************************/
	void lookAt_tilt(const GSvector3& _target, const float _direction);



	/**************************************************
	@brief y軸回転のみで被写体を見る
	@param[_target]		ターゲット
	@param[_elevation]	仰角
	**************************************************/
	void lookAt_pan(const GSvector3& _target, const float _elevation);



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
	@brief ズームリセット
	*******************************************************/
	void zoom_reset(void);



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
	Perspective						m_perspective;
	LookAt							m_lookAt;
	std::shared_ptr<CameraTarget>	m_cameraTarget_player;
	std::shared_ptr<CameraTarget>	m_cameraTarget_enemy;
};