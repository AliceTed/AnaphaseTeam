#pragma once
#ifndef _RANDOM_H_
#define _RANDOM_H_
/**
* @file Random.h
* @brief Randomを取得する関数オブジェクト
* @author 松尾裕也
* @date 2016/8/05
*/

namespace Math
{
	class Random
	{
	public:
		/**
		* @fn
		* @brief 範囲内の乱数を取得する
		* @param (_min) 最小値
		* @param (_max) 最大値
		* @return 整数範囲の乱数
		*/
		const int operator () (int _min, int _max)const;

		/**
		* @fn
		* @brief 範囲内の乱数を取得する
		* @param (_min) 最小値
		* @param (_max) 最大値
		* @param (_seed) シード値
		* @return 浮動小数点範囲の乱数
		*/
		const float operator () (float _min, float _max)const;

	};
}
#endif