#include "..\..\..\header\data\stream\SpawnReader.h"
#include "data/stream/SpawnConverter.h"
#include "data/stream/DataReader.h"
#include "spawn/SpawnData.h"
#include "data/Message.h"
#include "spawn/SpawnManager.h"
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
