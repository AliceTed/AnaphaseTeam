#include "..\..\..\header\data\stream\AttackReader.h"
#include "data/stream/AttackConverter.h"
#include "attack/LoadAttack.h"
#include "data/Message.h"
#include <fstream>
#include "data/json/Picojson.h"
#include "data/json/JObject.h"
#include "data/json/JArray.h"
void AttackReader::operator()(std::unordered_map<std::string,Attack>* _out, const std::string & _name, const std::string & _path, const std::string& _extension)
{
	std::string fullname = _path + _name + _extension;
	if (load(_out, fullname))return;

	Message error;
	error("ATTACKDATA", fullname);
}

const bool AttackReader::load(std::unordered_map<std::string, Attack>* _out, const std::string & _fullname) const
{
	std::ifstream fs(_fullname, std::ios::binary);
	if (!fs)return false;
	picojson::value value;
	fs >> value;
	fs.close();

	//JUtil::JObject obj(value.get<picojson::object>());
	picojson::object obj = value.get<picojson::object>();
	if (obj.count("Combo")==0)return false;
	picojson::array data = obj["Combo"].get<picojson::array>();// get<picojson::array>("Combo");

	AttackConverter convert;
	for (auto& i : data)
	{
		LoadAttack load;
		if (!convert(&load, i))return false;
		_out->insert(std::make_pair(load.selfID,Attack(load.parameter)));
	}
	return true;
}
