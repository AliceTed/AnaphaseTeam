#include "../../../header/data/stream/DataReader.h"
#include <fstream>
const bool DataReader::operator()(std::vector<std::string>* _out, const std::string & _name, const std::string& _extension, const std::string & _ignore)
{
	//ƒtƒ@ƒCƒ‹‚Ì“Ç‚Ýž‚Ý
	std::ifstream stream(_name + _extension);
	if (!stream)return false;
	std::string line;
	while (getline(stream, line))
	{
		if (!isIgnore(line, _ignore))
		{
			_out->emplace_back(line);
		}
	}
	return true;
}

const bool DataReader::isIgnore(const std::string & _text, const std::string & _ignore) const
{
	return std::string::npos!=_text.find(_ignore);
}
