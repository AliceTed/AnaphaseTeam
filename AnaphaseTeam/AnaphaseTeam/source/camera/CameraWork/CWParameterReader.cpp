#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../header/camera/CameraWork/CWParameterReader.h"

CWParameterReader::CWParameterReader(const std::string _fileName) :
	m_parameters()
{
	read(_fileName);
}



CWParameterReader::~CWParameterReader()
{

}



float CWParameterReader::get(const int _index)
{
	Parameter_Itr itr = m_parameters.begin();
	for (int i = 0; itr != m_parameters.end(); i++)
	{
		if (i == _index)
		{
			return *itr;
		}

		itr++;
	}

	return 0;
}



void CWParameterReader::read(const std::string _fileName)
{
	std::ifstream reading_file;
	std::string reading_line_buffer;

	const char delimiter = ' ';

	reading_file.open(_fileName, std::ios::in);

	if (reading_file.fail())
	{

		return;
	}

	while (getline(reading_file, reading_line_buffer))
	{
		std::string separated_string_buffer;
		std::istringstream line_separater(reading_line_buffer);
		for (int i = 0; std::getline(line_separater, separated_string_buffer, '='); i++)
		{
			if (i == 1)
			{
				m_parameters.emplace_back(std::stof(separated_string_buffer));
			}
		}
	}

	reading_file.close();
}