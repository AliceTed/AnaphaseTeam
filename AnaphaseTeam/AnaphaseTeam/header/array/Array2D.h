#pragma once
#ifndef _ARRAY2D_H_
#define _ARRAY2D_H_
#include <cassert>
#include<boost\scoped_array.hpp>
/**
* @file Array2D.h
* @brief 2次元配列用テンプレートクラス
* @author 松尾裕也
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
		* @brief コピーコンストラクタ
		* @param (_arrya) コピーしたいオブジェクトの参照
		*/
		Array2D(const Array2D & _array);

		/**
		* @fn
		* @brief 2次元配列の入れ替え
		* @param (_arrya) 入れ替えたい配列
		*/
		void swap(Array2D & _array);
		/**
		* @fn
		* @brief 代入する
		* @param (_array)指定2次元配列を代入
		* @return 代入後の自身の参照
		* @detail 自身が指定の二次元配列とスワップする
		*/
		Array2D& operator =(Array2D _array);

		/**
		* @fn
		* @brief 2次元配列内に外部から(,)でアクセスできるようにする
		* @param (_index0,_index1)指定の要素にアクセス
		* @return 指定番号の要素を参照で返す
		* @detail 配列外ならエラー
		*/
		const T& operator()(unsigned int _index0, unsigned int _index1) const;
		//変更可能版
		T& operator()(unsigned int _index0, unsigned int _index1);
		/**
		* @fn
		* @brief 指定の数字が要素内か調べる
		* @param (_index0,_index1)要素内か調べる数字
		* @return 指定の数字が要素内かどうか
		* @detail 配列外ならエラー
		*/
		const bool isInside(unsigned int _index0, unsigned int _index1)const;
		const unsigned int size0()const;
		const unsigned int size1()const;
	private:
		boost::scoped_array<T>m_Array;
		unsigned int m_Size0;//配列要素数0
		unsigned int m_Size1;//配列要素数1
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
				assert(index >= 0 && index < m_Size0*m_Size1 &&"配列外参照");
				m_Array[index] = _array.m_Array[index];
			}
		}
	}

	template<class T>
	void Array2D<T>::swap(Array2D & _array)
	{
		std::swap(m_Size0, _array.m_Size0);//要素数の入れ替え
		std::swap(m_Size1, _array.m_Size1);
		m_Array.swap(_array.m_Array);//要素の入れ替え
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
		unsigned int index = _index1 * m_Size0 + _index0;//実際のアクセス場所
		assert(index >= 0 && index < m_Size0*m_Size1 &&"配列外参照");
		return m_Array[index];
	}

	template<class T>
	const T & Array2D<T>::operator()(unsigned int _index0, unsigned int _index1) const
	{
		unsigned int index = _index1 * m_Size0 + _index0;//実際のアクセス場所
		assert(index >= 0 && index < m_Size0*m_Size1 &&"配列外参照");
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
