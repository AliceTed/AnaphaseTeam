#include "..\..\..\header\data\stream\SpawnConverter.h"
#include "../../../header/spawn/SpawnData.h"
#include <algorithm>
#include <sstream>
const bool SpawnConverter::operator()(SpawnData * _out, const std::string & _data) const
{
	std::string text = _data;
	std::replace(text.begin(), text.end(), ',', ' ');
	std::stringstream data(text);
	int active;
	data >> active;
	GSvector3 p;
	data >> p.x;
	data >> p.y;
	data >> p.z;
	float radius;
	data >> radius;
	int spawnNum;
	data >> spawnNum;
	int itype;
	data >> itype;
	if (data.fail())
	{
		return false;
	}
	_out->activeNumber = active;
	_out->area.position = p;
	_out->area.radius = radius;
	_out->spawnNum = spawnNum;
	_out->type = static_cast<ENEMY_TYPE>(itype);
	return true;
}

const bool SpawnConverter::operator()(SpawnData * _out,picojson::object & _data) const
{
	if (_data.count("ActiveNum") == 0)return false;
	int active =static_cast<int>(_data["ActiveNum"].get<double>());
	
	if (_data.count("Position") == 0)return false;
	picojson::array p_array = _data["Position"].get<picojson::array>();
	GSvector3 pos;
	for (unsigned int i = 0;i<p_array.size();i++)
	{
		pos.v[i] = static_cast<float>(p_array[i].get<double>());
	}

	if (_data.count("Radius") == 0)return false;
	float radius = static_cast<float>(_data["Radius"].get<double>());
	
	if (_data.count("SpawnNum") == 0)return false;
	int spawn = static_cast<float>(_data["SpawnNum"].get<double>());

	if (_data.count("EnemyType") == 0)return false;
	int type = static_cast<unsigned int>(_data["EnemyType"].get<double>()); 

	_out->activeNumber = active;
	_out->area.position = pos;
	_out->area.radius = radius;
	_out->spawnNum = spawn;
	_out->type = static_cast<ENEMY_TYPE>(type);
	return true;
}
