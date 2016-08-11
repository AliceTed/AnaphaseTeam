#pragma once
#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <cassert>
#include<boost\scoped_array.hpp>
/**
* @file Array.h
* @brief 配列用テンプレートクラス
* @author 松尾裕也
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
		* @brief コピーコンストラクタ
		* @param (_arrya) コピーしたいオブジェクトの参照
		*/
		Array(const Array & _array);

		/**
		* @fn
		* @brief 配列の入れ替え
		* @param (_arrya) 入れ替えたい配列
		*/
		void swap(Array & _array);

		Array& operator =(Array _array);

		/**
		* @fn
		* @brief 配列内に外部から()でアクセスできるようにする
		* @param (_index)指定の要素にアクセス
		* @return 指定番号の要素を参照で返す
		* @detail 配列外ならエラー
		*/
		const T& operator()(unsigned int _index) const;
		//変更可能版
		T& operator()(unsigned int _index);
		/**
		* @fn
		* @brief 指定の数字が要素内か調べる
		* @param (_index)要素内か調べる数字
		* @return 指定の数字が要素内かどうか
		* @detail 配列外ならエラー
		*/
		const bool isInside(unsigned int _index)const;
		const unsigned int size()const;
	private:
		boost::scoped_array<T>m_Array;
		unsigned int m_Size;//配列要素数
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
		std::swap(m_Size, _array.m_Size);//要素数の入れ替え
		m_Array.swap(_array.m_Array);//要素の入れ替え
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
		assert(_index >= 0 && _index < m_Size&&"配列外参照");
		return  m_Array[_index];
	}

	template<class T>
	const T & Array<T>::operator()(unsigned int _index) const
	{
		assert(_index >= 0 && _index < m_Size&&"配列外参照");
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