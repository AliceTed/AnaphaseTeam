#include "..\..\..\header\data\stream\SpawnReader.h"
#include "../../../header/data/stream/SpawnConverter.h"
#include "../../../header/spawn/SpawnData.h"
#include "../../../header/data/Message.h"
#include "../../../header/spawn/SpawnManager.h"
#include "../../../header/data/json/Picojson.h"
#include <fstream>
void SpawnReader::operator()(SpawnManager * _out, , const std::string & _name, const std::string & _path, const std::string & _extension) const
{
	std::string file = _path + _name + _extension;
	if (load(_out, file))
	{
		return;
	}
	Message error;
	error("SPAWNDATA", file);
}

const bool SpawnReader::load(SpawnManager * _out, const std::string & _file) const
{
	std::ifstream fs(_file, std::ios::binary);
	if (!fs)return false;
	picojson::value value;
	fs >> value;
	fs.close();
	
	SpawnConverter convert;
	for (auto& i : data)
	{
		SpawnData load;
		if (!convert(&load, i))return false;
		_out->add(SpawnPoint(load));
	}
	return true;
}
