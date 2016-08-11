#pragma once
#ifndef _LOADERROR_H_
#define _LOADERROR_H_
#include <string>
#include <gslib.h>
namespace Data
{
	class ErrorMessage
	{
	public:
		/**
		* @fn
		* @brief メッセージボックスでメッセージを表示
		* @param (_fileName) エラーがでたファイルの名前
		* @param (_dataName) データの種類
		*/
		void operator ()(const std::string& _fileName, const std::string& _dataName)const;
	};
	class LoadError
	{
	public:
		/**
		* @fn
		* @brief 完了しなかった時に指定関数を実行
		* @param (_isComplete) 完了したか
		* @param (_func)完了しなかった時に呼ばれる関数
		*/
		template<class Func>
		void operator ()(BOOL _isComplete, Func _func)const
		{
			if (_isComplete)return;
			_func();
		}
	};
}

#endif