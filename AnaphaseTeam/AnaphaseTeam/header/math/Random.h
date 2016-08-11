#pragma once
#ifndef _RANDOM_H_
#define _RANDOM_H_
/**
* @file Random.h
* @brief Random���擾����֐��I�u�W�F�N�g
* @author �����T��
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
		* @brief �������擾����
		* @param (_seed) �V�[�h�l
		* @return ����
		*/
		const unsigned int operator () (unsigned int _seed=0)const
		{
			assert(_seed >= 0);
			std::mt19937 m_mt(_seed);
			return  m_mt();
		}
		/**
		* @fn
		* @brief �͈͓��̗������擾����
		* @param (_min) �ŏ��l
		* @param (_max) �ő�l
		* @param (_seed) �V�[�h�l
		* @return �����͈̗͂���
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
		* @brief �͈͓��̗������擾����
		* @param (_min) �ŏ��l
		* @param (_max) �ő�l
		* @param (_seed) �V�[�h�l
		* @return ���������_�͈̗͂���
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