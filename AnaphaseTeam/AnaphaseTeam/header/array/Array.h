#pragma once
#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <cassert>
#include<boost\scoped_array.hpp>
/**
* @file Array.h
* @brief �z��p�e���v���[�g�N���X
* @author �����T��
* @date 2016/8/01
*/
namespace Array
{
	template<class T>
	class Array
	{
	public:
		Array(unsigned int _size=10);
		/**
		* @fn
		* @brief �R�s�[�R���X�g���N�^
		* @param (_arrya) �R�s�[�������I�u�W�F�N�g�̎Q��
		*/
		Array(const Array & _array);

		/**
		* @fn
		* @brief �z��̓���ւ�
		* @param (_arrya) ����ւ������z��
		*/
		void swap(Array & _array);

		Array& operator =(Array _array);

		/**
		* @fn
		* @brief �z����ɊO������()�ŃA�N�Z�X�ł���悤�ɂ���
		* @param (_index)�w��̗v�f�ɃA�N�Z�X
		* @return �w��ԍ��̗v�f���Q�ƂŕԂ�
		* @detail �z��O�Ȃ�G���[
		*/
		const T& operator()(unsigned int _index) const;
		//�ύX�\��
		T& operator()(unsigned int _index);
		/**
		* @fn
		* @brief �w��̐������v�f�������ׂ�
		* @param (_index)�v�f�������ׂ鐔��
		* @return �w��̐������v�f�����ǂ���
		* @detail �z��O�Ȃ�G���[
		*/
		const bool isInside(unsigned int _index)const;
		const unsigned int size()const;
	private:
		boost::scoped_array<T>m_Array;
		unsigned int m_Size;//�z��v�f��
	};
}
#endif // !_ARRAY_H_
namespace Array
{
	template<class T>
	Array<T>::Array(unsigned int _size)
		:m_Array(new T[_size]), m_Size(_size)
	{
	}
	template<class T>
	Array<T>::Array(const Array & _array)
		: m_Array(new T[_array.m_Size]), m_Size(_array.m_Size)
	{
		for (unsigned int i = 0; i < m_Size; i++)
		{
			m_Array[i] = _array.m_Array[i];
		}
	}

	template<class T>
	void Array<T>::swap(Array & _array)
	{
		std::swap(m_Size, _array.m_Size);//�v�f���̓���ւ�
		m_Array.swap(_array.m_Array);//�v�f�̓���ւ�
	}

	template<class T>
	Array<T> & Array<T>::operator=(Array _array)
	{
		this->swap(_array);
		return *this;
	}
	template<class T>
	T & Array<T>::operator()(unsigned int _index)
	{
		assert(_index >= 0 && _index < m_Size&&"�z��O�Q��");
		return  m_Array[_index];
	}

	template<class T>
	const T & Array<T>::operator()(unsigned int _index) const
	{
		assert(_index >= 0 && _index < m_Size&&"�z��O�Q��");
		return  m_Array[_index];
	}

	template<class T>
	const bool Array<T>::isInside(unsigned int _index) const
	{
		return 0 = > _index&&_index < m_Size;
	}

	template<class T>
	const unsigned int Array<T>::size() const
	{
		return m_Size;
	}
}