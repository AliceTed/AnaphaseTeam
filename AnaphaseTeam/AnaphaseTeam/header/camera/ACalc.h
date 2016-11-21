/*****************************************************
@file	ACalc.h
@brief	計算処理
@author Yuho Aritomi
@date	2016/09/21
*****************************************************/

#pragma once

#include <gslib.h>

class ACalc
{
public:
	/*************************************************
	@brief コンストラクタ
	*************************************************/
	ACalc(void);



	/*************************************************
	@brief デストラクタ
	*************************************************/
	~ACalc(void);



	/*************************************************
	@brief ターゲットを中心とした回転をする
	@param[_vector]		ベクター
	@param[_target]		ターゲット
	@param[_elevation]	仰角
	@param[_direction]	方位角
	@param[_distance]	距離
	*************************************************/
	void rotate(
		GSvector3*			_vector, 
		const GSvector3&	_target, 
		const float			_elevation, 
		const float			_direction, 
		const float			_distance
	);



	/*************************************************
	@brief ターゲットを追尾する
	@param[_vector] ベクター
	@param[_target] ターゲット
	@param[_speed] 
	[0~1]の範囲で指定
	範囲外の場合は次の式のようになります。
	→[a < 0 = 0],[a > 1 = 1]
	0の場合			: 追尾が働きません
	0と1以外の場合  : ディレイが付与された
					  追尾になります。
	1の場合         : ディレイが付与されていない
					  追尾になります。
	*************************************************/
	static void tracking(
		GSvector3* _vector, 
		const GSvector3& _target, 
		const float _speed
	);



	/*************************************************
	@brief 度をラジアンに変換する
	@param[_degree] 角度
	*************************************************/
	static void to_rad(float* _degree);



	/*************************************************
	@brief 始点から終点までの向きと大きさを調べる
	@param[_vector]			ベクター
	@param[_point_start]	始点の位置
	@param[_point_end]		終点の位置
	*************************************************/
	static void vector(
		GSvector3* _vector, 
		const GSvector3& _point_start, 
		const GSvector3& _point_end
	);
};