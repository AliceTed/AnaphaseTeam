#pragma once

#include <string>
#include <vector>
class DataReader
{
public:
	//��s���z��Ɋi�[
	const bool operator ()(std::vector<std::string>* _out, const std::string& _name, const std::string& _extension, const std::string & _ignore="#");
private:
	//_ignore������text�Ɋ܂܂�Ă�����true
	const bool isIgnore(const std::string& _text,const std::string& _ignore)const;
};
