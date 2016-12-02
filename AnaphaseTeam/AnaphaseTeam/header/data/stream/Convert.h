#pragma once
#include <string>
#include <vector>
class Convert
{
public:
	const bool operator()(std::vector<float>* _out, const std::string& _text, char _split = ',')const;
};