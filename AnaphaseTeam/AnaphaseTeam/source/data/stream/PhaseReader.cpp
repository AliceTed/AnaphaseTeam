#include "..\..\..\header\data\stream\PhaseReader.h"
#include <fstream>
#include "data/json/Picojson.h"
#include "data/stream/PhaseConverter.h"
#include "data/Message.h"
void PhaseReader::operator()(PhaseData * _out, const std::string & _name, const std::string & _path, const std::string & _extension) const
{
	std::string file = _path + _name + _extension;
	if (load(_out, file))return;
	Message error;
	error("PHASEDATA", file);
}

const bool PhaseReader::load(PhaseData * _out, const std::string & _file) const
{
	std::ifstream fs(_file,std::ios::binary);
	if (!fs)return false;
	picojson::value value;
	fs >> value;
	fs.close();
	PhaseConverter convert;
	return convert(_out, value);
}
