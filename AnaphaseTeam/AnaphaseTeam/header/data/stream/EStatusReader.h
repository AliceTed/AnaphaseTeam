#pragma once

#include <string>
#include "../../actor/Player/Status.h"
#include "../../attack/AttackStatus.h"

using namespace std;

class EStatusReader
{
public:
	void operator () (Status* _status, AttackStatus* _attack, float _gravity, const std::string& _name, const std::string& _path = "./res/data/", const std::string& _extension = ".JSON");

private:
	const bool load(Status* _status, AttackStatus* _attack, float _gravity, const string& _fullname)const;

};
