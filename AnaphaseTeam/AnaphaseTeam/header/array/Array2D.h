#pragma once
#ifndef _ARRAY2D_H_
#define _ARRAY2D_H_
#include <cassert>
#include<boost\scoped_array.hpp>
/**
* @file Array2D.h
* @brief 2�����z��p�e���v���[�g�N���X
* @author �����T��
* @date 2016/8/01
*/
namespace Array
{
	template<class T>
	class Array2D
	{
	public:
		Array2D(unsigned int _size0=2, unsigned int _size1=2);
		/**
		* @fn
		* @brief �R�s�[�R���X�g���N�^
		* @param (_arrya) �R�s�[�������I�u�W�F�N�g�̎Q��
		*/
		Array2D(const Array2D & _array);

		/**
		* @fn
		* @brief 2�����z��̓���ւ�
		* @param (_arrya) ����ւ������z��
		*/
		void swap(Array2D & _array);
		/**
		* @fn
		* @brief �������
		* @param (_array)�w��2�����z�����
		* @return �����̎��g�̎Q��
		* @detail ���g���w��̓񎟌��z��ƃX���b�v����
		*/
		Array2D& operator =(Array2D _array);

		/**
		* @fn
		* @brief 2�����z����ɊO������(,)�ŃA�N�Z�X�ł���悤�ɂ���
		* @param (_index0,_index1)�w��̗v�f�ɃA�N�Z�X
		* @return �w��ԍ��̗v�f���Q�ƂŕԂ�
		* @detail �z��O�Ȃ�G���[
		*/
		const T& operator()(unsigned int _index0, unsigned int _index1) const;
		//�ύX�\��
		T& operator()(unsigned int _index0, unsigned int _index1);
		/**
		* @fn
		* @brief �w��̐������v�f�������ׂ�
		* @param (_index0,_index1)�v�f�������ׂ鐔��
		* @return �w��̐������v�f�����ǂ���
		* @detail �z��O�Ȃ�G���[
		*/
		const bool isInside(unsigned int _index0, unsigned int _index1)const;
		const unsigned int size0()const;
		const unsigned int size1()const;
	private:
		boost::scoped_array<T>m_Array;
		unsigned int m_Size0;//�z��v�f��0
		unsigned int m_Size1;//�z��v�f��1
	};
}
#endif // !_ARRAY2D_H_
namespace Array
{
	template<class T>
	Array2D<T>::Array2D(unsigned int _size0, unsigned int _size1)
		:m_Array(new T[_size0*_size1]), m_Size0(_size0), m_Size1(_size1)
	{
	}
	template<class T>
	Array2D<T>::Array2D(const Array2D & _array)
		: m_Array(new T[_array.m_Size0*_array.m_Size1]),
		m_Size0(_array.m_Size0),
		m_Size1(_array.m_Size1)
	{
		for (unsigned int i = 0; i < m_Size0; i++)
		{
			for (unsigned int j = 0; j < m_Size1; j++)
			{
				unsigned index = j * m_Size0 + i;
				assert(index >= 0 && index < m_Size0*m_Size1 &&"�z��O�Q��");
				m_Array[index] = _array.m_Array[index];
			}
		}
	}

	template<class T>
	void Array2D<T>::swap(Array2D & _array)
	{
		std::swap(m_Size0, _array.m_Size0);//�v�f���̓���ւ�
		std::swap(m_Size1, _array.m_Size1);
		m_Array.swap(_array.m_Array);//�v�f�̓���ւ�
	}

	template<class T>
	Array2D<T> & Array2D<T>::operator=(Array2D _array)
	{
		this->swap(_array);
		return *this;
	}
	template<class T>
	T & Array2D<T>::operator()(unsigned int _index0, unsigned int _index1)
	{
		unsigned int index = _index1 * m_Size0 + _index0;//���ۂ̃A�N�Z�X�ꏊ
		assert(index >= 0 && index < m_Size0*m_Size1 &&"�z��O�Q��");
		return m_Array[index];
	}

	template<class T>
	const T & Array2D<T>::operator()(unsigned int _index0, unsigned int _index1) const
	{
		unsigned int index = _index1 * m_Size0 + _index0;//���ۂ̃A�N�Z�X�ꏊ
		assert(index >= 0 && index < m_Size0*m_Size1 &&"�z��O�Q��");
		return m_Array[index];
	}

	template<class T>
	const bool Array2D<T>::isInside(unsigned int _index0, unsigned int _index1) const
	{
		if (_index1 < 0)
		{
			return false;
		}
		if (_index0 < 0)
		{
			return false;
		}
		if (m_Size1 >= _index1)
		{
			return false;
		}
		if (m_Size0 >= _index0)
		{
			return false;
		}
		return true;
	}

	template<class T>
	const unsigned int Array2D<T>::size0() const
	{
		return m_Size0;
	}
	template<class T>
	const unsigned int Array2D<T>::size1() const
	{
		return m_Size1;
	}
}
