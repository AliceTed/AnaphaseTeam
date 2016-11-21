/***********************************************************
@file Perspective.h
@brief 遠近法
@author Yuho Artiomi
@data 2016-08-27 Ver1.00
***********************************************************/
#pragma once

#include <gslib.h>

class Perspective
{
public:
	//float fov;		/** @brief 視野 */
	//float aspect;	/** @brief 面 */
	//float near;		/** @brief 近い距離 */
	//float far;		/** @brief 遠い距離 */

	/*******************************************************
	@brief コンストラクタ
	*******************************************************/
	Perspective(void);

	/*******************************************************
	@brief コンストラクタ
	@param[_fov]	視野角
	@param[_aspect] アスペクト
	@param[_near]	近クリップ
	@param[_far]	遠クリップ
	*******************************************************/
	Perspective(
		const float _fov, 
		const float _aspect, 
		const float _near, 
		const float _far
	);



	/*******************************************************
	@brief デストラクタ
	*******************************************************/
	~Perspective();



	/*******************************************************
	@brief 初期化
	@param[_fov]	視野角
	@param[_aspect] アスペクト
	@param[_near]	近クリップ
	@param[_far]	遠クリップ
	*******************************************************/
	void initialize(
		const float _fov,
		const float _aspect,
		const float _near,
		const float _far
	);



	/*******************************************************
	@brief 更新
	*******************************************************/
	void update(void);



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



	/*******************************************************
	@return 視野角
	*******************************************************/
	const float fov(void) const
	{
		return m_fov;
	}
	/*******************************************************
	@return アスペクト
	*******************************************************/
	const float aspect(void) const
	{
		return m_aspect;
	}
	/*******************************************************
	@return 近クリップ
	*******************************************************/
	const float near(void) const
	{
		return m_near;
	}
	/*******************************************************
	@return 遠クリップ
	*******************************************************/
	const float far(void) const
	{
		return m_far;
	}
	/*******************************************************
	@return 投射行列
	*******************************************************/
	const GSmatrix4& matProj(void) const
	{
		return m_matProjection;
	}

private:
	//ズーム処理
	void zoom_update(const float _speed);

private:
	float		m_fov;
	float		m_aspect;
	float		m_near;
	float		m_far;

	GSmatrix4	m_matProjection;

	float		m_fov_min;
	float		m_fov_max;

	const float FOV_DEF = 90.0f;
	const float FOV_MIN = 0.1f;
	const float FOV_MAX = 360.0f;
};