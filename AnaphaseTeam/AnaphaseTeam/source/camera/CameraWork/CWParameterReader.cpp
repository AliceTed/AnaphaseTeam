#include <iostream>
#include <fstream>
#include <sstream>
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
	//イテレーターで回して指定した要素数にたどり着けばその要素の数値を返す
	Parameter_Itr itr = m_parameters.begin();
	for (int i = 0; itr != m_parameters.end(); i++)
	{
		//指定した要素数があれば
		if (i == _index)
		{
			return *itr;
		}

		itr++;
	}

	//指定した要素数がなければエラー０を返す
	Message error;
	std::stringstream ss;
	ss << _index << "番目の要素がありません";
	error(ss.str(), ss.str());
	return 0;
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
			if (i == 1)
			{
				m_parameters.emplace_back(std::stof(separated_string_buffer));
			}
		}
	}

	//読み込んだファイルを閉じる
	reading_file.close();
}