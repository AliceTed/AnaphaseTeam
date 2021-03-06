#pragma once

#include <string>
#include <vector>
class DataReader
{
public:
	//一行ずつ配列に格納
	const bool operator ()(std::vector<std::string>* _out, const std::string& _name, const std::string& _extension, const std::string & _ignore="#");
private:
	//_ignore文字がtextに含まれていたらtrue
	const bool isIgnore(const std::string& _text,const std::string& _ignore)const;
};
