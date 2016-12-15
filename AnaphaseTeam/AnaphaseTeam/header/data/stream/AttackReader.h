#pragma once
#include <unordered_map>
#include "../../attack/Attack.h"
class AttackReader
{
public:
	void operator()(std::unordered_map<std::string,Attack>* _out, const std::string& _name, const std::string& _path="./res/data/");
private: 
	const bool load(std::unordered_map<std::string, Attack>* _out, const std::string& _fullname)const;

};