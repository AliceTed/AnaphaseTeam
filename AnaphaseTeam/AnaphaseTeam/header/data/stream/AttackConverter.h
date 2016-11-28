#pragma once
#include <string>
struct LoadAttack;
class AttackConverter
{
public:
	const bool operator()(LoadAttack* _out, const std::string& _data)const;
};
