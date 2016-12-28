#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../../../header/camera/CameraWork/CWParameterReader.h"
#include "../../../header/data/Message.h"

CWParameterReader::CWParameterReader(const std::string _fileName) :
	m_parameters()
{
	//読み込み処理
	read(_fileName);
}

CWParameterReader::~CWParameterReader()
{

}

float CWParameterReader::get(const int _index)
{
	if (_index < 0 || static_cast<unsigned int>(_index) >= m_parameters.size())
	{
		//指定した要素数がなければエラー０を返す
		Message error;
		std::stringstream ss;
		ss << _index << "番目の要素がありません";
		error(ss.str(), ss.str());
		return 0;
	}

	return m_parameters[_index];
}

float CWParameterReader::operator[](int _index)
{
	//取得処理
	return get(_index);
}

void CWParameterReader::read(const std::string _fileName)
{
	std::ifstream reading_file;
	std::string reading_line_buffer;
	std::vector<std::string> vec(2);

	//ファイルを開く
	reading_file.open(_fileName, std::ios::in);

	//ファイルがなければエラーを出力して終了
	if (reading_file.fail())
	{
		Message error;
		error(_fileName, _fileName);
		return;
	}

	//読み込んだファイルの中身を文字列にする（一行、１ループ）
	while (getline(reading_file, reading_line_buffer))
	{
		std::string separated_string_buffer;
		std::istringstream line_separater(reading_line_buffer);
		//読み込んだ文字列を'='区切りにする
		for (int i = 0; std::getline(line_separater, separated_string_buffer, '='); i++)
		{
			//'='後の値を取得する
			vec[i] = separated_string_buffer;
		}

		m_parameters.emplace_back(std::stof(separated_string_buffer));
	}

	//読み込んだファイルを閉じる
	reading_file.close();
}