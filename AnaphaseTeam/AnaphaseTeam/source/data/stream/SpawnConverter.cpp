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
