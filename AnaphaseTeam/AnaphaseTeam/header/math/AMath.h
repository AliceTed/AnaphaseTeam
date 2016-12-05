/******************************************************
@file	AMath.h
@brief	計算
@author Yuuho Aritomi
@date	2016/12/02
******************************************************/
#pragma once

#include <gslib.h>

class AMath
{
public:
	/*************************************************
	@brief 円周率
	*************************************************/
	static const float PI;

public:
	/*************************************************
	@brief ラジアンに変換
	@param[_deg]	角度
	@return			ラジアン値
	*************************************************/
	static float to_rad(float _deg);

	/*************************************************
	@brief ラジアンに変換
	@param[_rotate]		回転軸
	@return				回転軸（ラジアン変換済み）
	*************************************************/
	static GSvector2 to_rad(const GSvector2& _rotate);

	/*************************************************
	@brief 角度に変換
	@param[_rad]	ラジアン
	@return			角度
	*************************************************/
	static float to_deg(float _rad);


	/*************************************************
	@brief 角度の正規化
	@param[_angle]	角度
	@return			-360 ~ 360までの数値
	*************************************************/
	static float normalizeAngle(float _angle);


	/*************************************************
	@brief 角度差を求める
	@param[_deg1]	角度１	
	@param[_deg2]	角度２
	@return			角度
	*************************************************/
	static float subtractAngle(float _deg1, float _deg2);


	/*************************************************
	@brief 球面座標を使った回転
	@param[_center]		中心点
	@param[_rotate]		回転角度
						x : 仰角
						y : 方位角
	@param[_distance]	中心からの距離
	*************************************************/
	static GSvector3 rotate_sphericalCoordinates(
		const GSvector3&	_center,
		const GSvector2&	_rotate,
		const float			_distance
	);


	/*************************************************
	@brief pitch,yow回転のラープ
	@param[_my]			自分
	@param[_target]		ターゲット
	@param[_speed]		速度
	*************************************************/
	static void lerp_eleDir(
		GSvector2*			_my,
		const GSvector2&	_target,
		float				_speed
	);
};

