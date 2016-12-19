#pragma once
#include <string>
struct PhaseData;
class PhaseReader
{
public:
	void operator()(PhaseData* _out,const std::string& _name, const std::string& _path="./res/data/", const std::string& _extension=".JSON")const;
private:
	const bool load(PhaseData* _out,const std::string& _file)const;
};