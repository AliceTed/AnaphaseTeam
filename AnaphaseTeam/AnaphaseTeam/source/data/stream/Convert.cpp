#include "../../../header/data/stream/Convert.h"
#include<sstream> 
const bool Convert::operator()(std::vector<float>* _out, const std::string & _text, char _split) const
{
	std::string token;
	std::istringstream stream(_text);
	//1�s�̂����A������ƃR���}�𕪊�����
	while (getline(stream, token, _split))
	{
		try
		{
			_out->emplace_back(std::stof(token));
		}
		catch (const std::exception&)
		{
			return false;
		}
	}
	return true;
}
