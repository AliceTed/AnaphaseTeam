#pragma once
#ifndef _RANDOM_H_
#define _RANDOM_H_
/**
* @file Random.h
* @brief Random���擾����֐��I�u�W�F�N�g
* @author �����T��
* @date 2016/8/05
*/

namespace Math
{
	class Random
	{
	public:
		/**
		* @fn
		* @brief �͈͓��̗������擾����
		* @param (_min) �ŏ��l
		* @param (_max) �ő�l
		* @return �����͈̗͂���
		*/
		const int operator () (int _min, int _max)const;

		/**
		* @fn
		* @brief �͈͓��̗������擾����
		* @param (_min) �ŏ��l
		* @param (_max) �ő�l
		* @param (_seed) �V�[�h�l
		* @return ���������_�͈̗͂���
		*/
		const float operator () (float _min, float _max)const;

	};
}
#endif