#pragma once

#include <string>
#include <vector>
class DataWriter
{
public:
	// �t�@�C����1�s����������
	const bool operator()(const std::vector<std::string>& _in, const std::string& _name, const std::string& _extension)const;
};