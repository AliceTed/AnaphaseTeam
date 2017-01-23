#include "../../../header/data/stream/EStatusReader.h"
#include <fstream>
#include "../../../header/data/Message.h"
#include "../../../header/data/json/Picojson.h"

void EStatusReader::operator()(Status* _status, AttackStatus* _attack, float _gravity, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	string fullname = _path + _name + _extension;
	if (load(_status, _attack, _gravity, fullname))return;

	Message error;
	error("ESTATUSDATA", fullname);
}

const bool EStatusReader::load(Status* _status, AttackStatus* _attack, float _gravity, const string & _fullname) const
{
	ifstream fs(_fullname, ios::binary);
	if (!fs)return false;
	picojson::value value;
	fs >> value;
	fs.close();

	picojson::object obj = value.get<picojson::object>();
	if (obj.count("EStatus") == 0)return false;
	picojson::object data = obj["EStatus"].get<picojson::object>();

	float hp = static_cast<float>(data["EnemyHP"].get<double>());
	_status->m_maxHp = hp;

	_attack->m_power = static_cast<float>(data["Power"].get<double>());
	_gravity = static_cast<float>(data["Gravity"].get<double>());

	return true;
}
