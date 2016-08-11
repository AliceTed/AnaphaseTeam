#pragma once
#ifndef _RANDOM_H_
#define _RANDOM_H_
/**
* @file Random.h
* @brief Randomを取得する関数オブジェクト
* @author 松尾裕也
* @date 2016/8/05
*/
#include <random>
#include <cassert>
namespace Math
{
	class Random
	{
	public:
		/**
		* @fn
		* @brief 乱数を取得する
		* @param (_seed) シード値
		* @return 乱数
		*/
		const unsigned int operator () (unsigned int _seed=0)const
		{
			assert(_seed >= 0);
			std::mt19937 m_mt(_seed);
			return  m_mt();
		}
		/**
		* @fn
		* @brief 範囲内の乱数を取得する
		* @param (_min) 最小値
		* @param (_max) 最大値
		* @param (_seed) シード値
		* @return 整数範囲の乱数
		*/
		const int operator () (int _min,int _max, unsigned int _seed=0)const
		{
			assert(_seed >= 0);
			std::mt19937 m_mt(_seed);
			std::uniform_int_distribution<int> range(_min,_max);
			return range(m_mt);
		}
		/**
		* @fn
		* @brief 範囲内の乱数を取得する
		* @param (_min) 最小値
		* @param (_max) 最大値
		* @param (_seed) シード値
		* @return 浮動小数点範囲の乱数
		*/
		const float operator () (float _min, float _max, unsigned int _seed=0)const
		{
			assert(_seed >= 0);
			std::mt19937 m_mt(_seed);
			std::uniform_real_distribution<float> range(_min, _max);
			return range(m_mt);
		}
	};
}
#endif