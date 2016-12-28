#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../../../header/camera/CameraWork/CWParameterReader.h"
#include "../../../header/data/Message.h"

CWParameterReader::CWParameterReader(const std::string _fileName) :
	m_parameters()
{
	//�ǂݍ��ݏ���
	read(_fileName);
}

CWParameterReader::~CWParameterReader()
{

}

float CWParameterReader::get(const int _index)
{
	if (_index < 0 || static_cast<unsigned int>(_index) >= m_parameters.size())
	{
		//�w�肵���v�f�����Ȃ���΃G���[�O��Ԃ�
		Message error;
		std::stringstream ss;
		ss << _index << "�Ԗڂ̗v�f������܂���";
		error(ss.str(), ss.str());
		return 0;
	}

	return m_parameters[_index];
}

float CWParameterReader::operator[](int _index)
{
	//�擾����
	return get(_index);
}

void CWParameterReader::read(const std::string _fileName)
{
	std::ifstream reading_file;
	std::string reading_line_buffer;
	std::vector<std::string> vec(2);

	//�t�@�C�����J��
	reading_file.open(_fileName, std::ios::in);

	//�t�@�C�����Ȃ���΃G���[���o�͂��ďI��
	if (reading_file.fail())
	{
		Message error;
		error(_fileName, _fileName);
		return;
	}

	//�ǂݍ��񂾃t�@�C���̒��g�𕶎���ɂ���i��s�A�P���[�v�j
	while (getline(reading_file, reading_line_buffer))
	{
		std::string separated_string_buffer;
		std::istringstream line_separater(reading_line_buffer);
		//�ǂݍ��񂾕������'='��؂�ɂ���
		for (int i = 0; std::getline(line_separater, separated_string_buffer, '='); i++)
		{
			//'='��̒l���擾����
			vec[i] = separated_string_buffer;
		}

		m_parameters.emplace_back(std::stof(separated_string_buffer));
	}

	//�ǂݍ��񂾃t�@�C�������
	reading_file.close();
}