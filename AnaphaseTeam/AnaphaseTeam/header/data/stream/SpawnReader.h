#pragma once
#include <string>
class SpawnManager;
class SpawnReader
{
public:
	void operator()(SpawnManager* _out, , const std::string& _name, const std::string& _path = "./res/data/", const std::string& _extension = ".JSON")const;
private: 
	const bool load(SpawnManager* _out,const std::string& _fullname)const;
};