#pragma once

#include "../../actor/Player/Status.h"
#include "../../actor/Player/Gauge.h"

using namespace std;

class StatusReader
{
public:
	void operator () (Status* _status, Gauge* _gauge, const std::string& _name, const std::string& _path = "./res/data/", const std::string& _extension = ".JSON");

private:
	const bool load(Status* _status, Gauge* _gauge, const string& _fullname)const;

};