#include "..\..\..\header\data\stream\SpawnReader.h"
#include "../../../header/data/stream/SpawnConverter.h"
#include "../../../header/data/stream/DataReader.h"
#include "../../../header/spawn/SpawnData.h"
#include "../../../header/data/Message.h"
#include "../../../header/spawn/SpawnManager.h"
void SpawnReader::operator()(SpawnManager * _out, const std::string & _name, const std::string & _path) const
{
	if (load(_out, _path + _name))
	{
		return;
	}
	Message error;
	error("SPAWNDATA", _path + _name);
}

const bool SpawnReader::load(SpawnManager * _out, const std::string & _fullname) const
{
	std::vector<std::string> data;
	data.clear();
	DataReader reader;
	if (!reader(&data, _fullname, ".esp"))return false;
	SpawnConverter convert;
	for (auto& i : data)
	{
		SpawnData load;
		if (!convert(&load, i))return false;
		_out->add(SpawnPoint(load));
	}
	return true;
}
