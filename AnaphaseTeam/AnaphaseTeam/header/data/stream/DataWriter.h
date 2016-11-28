#pragma once

#include <string>
#include <vector>
class DataWriter
{
public:
	// ファイルに1行ずつ書き込み
	const bool operator()(const std::vector<std::string>& _in, const std::string& _name, const std::string& _extension)const;
};