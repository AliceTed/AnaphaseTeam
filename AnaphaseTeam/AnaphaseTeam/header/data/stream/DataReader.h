#pragma once

#include <string>
#include <vector>
class DataReader
{
public:
	//ˆês‚¸‚Â”z—ñ‚ÉŠi”[
	const bool operator ()(std::vector<std::string>* _out, const std::string& _name, const std::string& _extension, const std::string & _ignore="#");
private:
	//_ignore•¶š‚ªtext‚ÉŠÜ‚Ü‚ê‚Ä‚¢‚½‚çtrue
	const bool isIgnore(const std::string& _text,const std::string& _ignore)const;
};
