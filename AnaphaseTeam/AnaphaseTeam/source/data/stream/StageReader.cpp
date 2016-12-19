#include "..\..\..\header\data\stream\StageReader.h"
#include <fstream>
#include "../../../header/data/json/Picojson.h"
#include "../../../header/data/stream/StageConverter.h"
#include "../../../header/data/Message.h"
void StageReader::operator()(StageData * _out, const std::string & _name, const std::string & _path, const std::string & _extension) const
{
	std::string file = _path + _name + _extension;
	if (load(_out, file))return;
	Message error;
	error("STAGEDATA", file);
}

const bool StageReader::load(StageData * _out, const std::string & _file) const
{
	std::ifstream fs(_file, std::ios::binary);
	if (!fs)return false;
	picojson::value value;
	fs >> value;
	fs.close();
	StageConverter convert;
	return convert(_out, value);
}
