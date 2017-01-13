#include "../../../header/data/stream/StatusReader.h"
#include <fstream>
#include "../../../header/data/stream/StatusConverter.h"
#include "../../../header/actor/Player/LoadStatus.h"
#include "../../../header/data/Message.h"
#include "../../../header/data/json/Picojson.h"

void StatusReader::operator()(Status* _out, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	string fullname = _path + _name + _extension;
	if (load(_out, fullname))return;

	Message error;
	error("STATUSDATA", fullname);
}

const bool StatusReader::load(Status* _out, const string & _fullname) const
{
	ifstream fs(_fullname, ios::binary);
	if (!fs)return false;
	picojson::value value;
	fs >> value;
	fs.close();

	//JUtil::JObject obj(value.get<picojson::object>());
	picojson::object obj = value.get<picojson::object>();
	if (obj.count("Status") == 0)return false;
	picojson::object data = obj["Status"].get<picojson::object>();// get<picojson::array>("Combo");

	float hp = data["PlayerHP"].get<double>();
	_out->m_maxHp = hp;

	//StatusConverter convert;
	/*for (auto& i : data)
	{
		LoadStatus load;
		if (!convert(&load, i))return false;
		_out->insert(make_pair(load.selfID, Status(0, load.parameter)));
	}*/

	return true;
}
