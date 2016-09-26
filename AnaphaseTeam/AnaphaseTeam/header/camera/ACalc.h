/**
@file ACalc.h
@brief 計算処理
@author Yuho Aritomi
@date 2016/09/21
*/

#pragma once

#include <gslib.h>

class ACalc
{
public:
	/**
	@brief デフォルトコンストラクタ
	*/
	ACalc(void);

	/**
	@brief デストラクタ
	*/
	~ACalc(void);

	/**
	@brief ターゲットを中心とした回転をする
	*/
	static void rotate(GSvector3* _vector, const GSvector3* _target, const float _pitch, const float _yow, const float _distance);

	/**
	@brief ターゲットを追尾する
	@param[_speed] 
	[0~1]の範囲で指定（範囲外の場合は次の式のようになります→[a < 0 = 0],[a > 1 = 1]）
	0の場合			: 追尾が働きません
	0と1以外の場合  : ディレイが付与された追尾になります
	1の場合         : ディレイが付与されていない追尾になります
	*/
	static void tracking(GSvector3* _vector, const GSvector3* _target, const float _speed);

	/**
	@brief 二つの値のうち大きいほうを代入する
	*/
	static void max(int* _num, const int _a, const int _b);
	static void max(float* _num, const float _a, const float _b);

	/**
	@brief 二つの値のうち小さいほうを代入する
	*/
	static void min(int* _num, const int _a, const int _b);
	static void min(float* _num, const float _a, const float _b);

	/**
	@brief 指定した値が最小値、最大値を超えないようにする
	*/
	static void clamp(int* _num, const int _min, const int _max);
	static void clamp(float* _num, const float _min, const float _max);

	/**
	@brief 度をラジアンに変換する
	*/
	static void to_rad(float* _degree);

	/**
	@brief 始点から終点までの向きと大きさを調べる
	*/
	static void vector(GSvector3* _vector, const GSvector3* _start_point, const GSvector3* _end_point);
};