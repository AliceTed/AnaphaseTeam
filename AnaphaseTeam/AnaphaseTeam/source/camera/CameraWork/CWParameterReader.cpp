#include <iostream>
#include <fstream>
#include <sstream>
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
	//�C�e���[�^�[�ŉ񂵂Ďw�肵���v�f���ɂ��ǂ蒅���΂��̗v�f�̐��l��Ԃ�
	Parameter_Itr itr = m_parameters.begin();
	for (int i = 0; itr != m_parameters.end(); i++)
	{
		//�w�肵���v�f���������
		if (i == _index)
		{
			return *itr;
		}

		itr++;
	}

	//�w�肵���v�f�����Ȃ���΃G���[�O��Ԃ�
	Message error;
	std::stringstream ss;
	ss << _index << "�Ԗڂ̗v�f������܂���";
	error(ss.str(), ss.str());
	return 0;
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
			if (i == 1)
			{
				m_parameters.emplace_back(std::stof(separated_string_buffer));
			}
		}
	}

	//�ǂݍ��񂾃t�@�C�������
	reading_file.close();
}