#pragma once

#include <unordered_map>
#include "../../actor/Player/Status.h"

using namespace std;

class StatusReader
{
public:
	void operator () (Status* _out, const std::string& _name, const std::string& _path = "./res/data/", const std::string& _extension = ".JSON");

private:
	const bool load(Status* _out, const string& _fullname)const;

};