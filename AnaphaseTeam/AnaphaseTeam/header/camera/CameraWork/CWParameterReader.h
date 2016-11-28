/*************************************************************
@file	CWParameterReader.h
@brief	カメラワークのパラメータを外部から読み込む
@author Yuuho Aritomi
@date	2016/11/28
*************************************************************/
#pragma once

#include <string>
#include <list>

typedef std::list<float> Parameter;
typedef Parameter::iterator Parameter_Itr;

class CWParameterReader
{
public:
	CWParameterReader(const std::string _fileName);



	~CWParameterReader();



	float get(const int _index);

private:
	void read(const std::string _fileName);

	Parameter m_parameters;
};