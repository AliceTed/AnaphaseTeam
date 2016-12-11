/**
@file	CWParameterReader.h
@brief	カメラワークのパラメータを外部から読み込む
@author Yuuho Aritomi
@date	2016/11/28
*/
#pragma once

#include <string>
#include <list>

class CWParameterReader
{
public:
	/**
	@brief コンストラクタ
	@param[_fileName] ファイルの名前
	*/
	CWParameterReader(const std::string _fileName);

	//デストラクタ
	~CWParameterReader();

	/**
	@brief	取得
			指定した要素数がなければエラー文と０を返す
	@param[_index] 要素数
	@return 数値
	*/
	float get(const int _index);

	/**
	@brief 配列演算子オーバロード
	@param[_index] 要素数
	@return 数値
	*/
	float operator[](int _index);

private:
	//読み込み処理
	void read(const std::string _fileName);

private:
	using Parameter = std::list<float>;
	using Parameter_Itr = Parameter::iterator;

	Parameter m_parameters;
};