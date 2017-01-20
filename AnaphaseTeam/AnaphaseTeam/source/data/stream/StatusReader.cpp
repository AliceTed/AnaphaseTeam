#include "../../../header/data/stream/StatusReader.h"
#include <fstream>
#include "../../../header/data/stream/StatusConverter.h"
#include "../../../header/actor/Player/LoadStatus.h"
#include "../../../header/data/Message.h"
#include "../../../header/data/json/Picojson.h"

void StatusReader::operator()(Status* _status, Gauge* _gauge, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	string fullname = _path + _name + _extension;
	if (load(_status, _gauge, fullname))return;

	Message error;
	error("STATUSDATA", fullname);
}

const bool StatusReader::load(Status* _status, Gauge* _gauge,const string & _fullname) const
{
	ifstream fs(_fullname, ios::binary);
	if (!fs)return false;
	picojson::value value;
	fs >> value;
	fs.close();

	picojson::object obj = value.get<picojson::object>();
	if (obj.count("Status") == 0)return false;
	picojson::object data = obj["Status"].get<picojson::object>();

	float hp = data["PlayerHP"].get<double>();
	_status->m_maxHp = hp;

	float defaultGauge = data["DefaultGauge"].get<double>();
	_gauge->m_gauge = defaultGauge;

	float increaseGauge = data["IncreaseGauge"].get<double>();
	_gauge->m_increaseGauge = increaseGauge;

	return true;
}
