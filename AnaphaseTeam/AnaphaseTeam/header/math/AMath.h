/******************************************************
@file	AMath.h
@brief	計算
@author Yuuho Aritomi
@date	2016/12/02
******************************************************/
#pragma once

#include <gslib.h>
#include <list>
#include <vector>

class AMath
{
public:
	/**
	@brief 円周率
	*/
	static const float PI;

public:
	/**
	@fn
	@brief ラジアンに変換(GSvector2用)
	@param[_rotate]		回転軸
	@return				回転軸（ラジアン変換済み）
	*/
	static GSvector2 to_rad(const GSvector2& _rotate);
	/**
	@fn
	@brief 角度の正規化
	@param[_angle]	角度
	@return			-360 ~ 360までの数値
	*/
	static float normalizeAngle(float _angle);
	/**
	@fn
	@brief 角度差を求める
	@param[_deg1]	角度１	
	@param[_deg2]	角度２
	@return			角度
	*/
	static float subtractAngle(float _deg1, float _deg2);
	/**
	@fn
	@brief ２点間の３次元ベクトルを求める
	@param[_p1] 点１
	@param[_p2] 点２
	@return		３次元ベクトル
	*/
	static GSvector3 vec3_vector(const GSvector3 _p1, const GSvector3 _p2);
	/**
	@fn
	@brief ２点間の中点を求める
	@param[_p1] 点１
	@param[_p2] 点２
	@return		中点
	*/
	static GSvector3 vec3_center(const GSvector3 _p1, const GSvector3 _p2);
	/**
	@fn
	@brief 球面座標を使った回転
	@param[_center]		中心点
	@param[_rotate]		回転角度
						x : 仰角
						y : 方位角
	@param[_distance]	中心からの距離
	*/
	static GSvector3 ballRotate(
		const GSvector3&	_center,
		const GSvector2&	_rotate,
		const float			_distance
	);
	/**
	@fn
	@brief 回転のラープ
	@param _my		自分
	@param _target	ターゲット
	@param _speed	速度
	*/
	static void lerp_angle(float* _my, const float _target, const float _speed);
	/**
	@fn
	@brief pitch,yow回転のラープ
	@param[_my]			自分
	@param[_target]		ターゲット
	@param[_speed]		速度
	*/
	static void lerp_eleDir(GSvector2* _my, const GSvector2& _target, const float _speed);
	/**
	@fn
	@brief 点ｐが有向線分の左右どちらにあるかを調べる
	@param[_p]		点ｐ
	@param[_start]	有向線分始点
	@param[_end]	有向線分終点
	@return			左側：１
					直線上：０
					右側：−１
	*/
	static int side(const GSvector2& _p, const GSvector2& _start, const GSvector2& _end);
	/**
	@fn
	@brief 数値のｎ乗を求める
	@param[_num]	数値
	@param[_n]		n乗
	@return 結果
	*/
	static float pow(float _num, int _n);
};
