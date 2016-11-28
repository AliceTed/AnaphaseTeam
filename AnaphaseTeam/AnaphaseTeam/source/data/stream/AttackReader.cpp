#include "..\..\..\header\data\stream\AttackReader.h"
#include "../../../header/data/stream/AttackConverter.h"
#include "../../../header/data/stream/DataReader.h"
#include "../../../header/attack/LoadAttack.h"
#include "../../../header/data/LoadError.h"
void AttackReader::operator()(std::unordered_map<ATTACK_TYPE,Attack>* _out, const std::string & _name, const std::string & _path)
{
	if (load(_out, _path + _name))
	{
		return;
	}
	Data::ErrorMessage error;
	error(_path + _name, "ATTACKDATA");
}

const bool AttackReader::load(std::unordered_map<ATTACK_TYPE, Attack>* _out, const std::string & _fullname) const
{
	std::vector<std::string> data;
	data.clear();
	DataReader reader;
	if (!reader(&data, _fullname, ".atk"))return false;
	AttackConverter convert;
	for (auto& i : data)
	{
		LoadAttack load;
		if (!convert(&load, i))return false;
		_out->insert(std::make_pair(load.m_type, load.m_attack));
	}
	return true;
}
