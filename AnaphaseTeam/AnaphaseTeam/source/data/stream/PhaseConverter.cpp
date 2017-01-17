#include "..\..\..\header\data\stream\PhaseConverter.h"
#include "stage/PhaseData.h"
const bool PhaseConverter::operator()(PhaseData * _out,picojson::value & _value) const
{
	picojson::object parent = _value.get<picojson::object>();
	if (parent.count("Phase") == 0)return false;
	picojson::value obj = parent["Phase"];
	//Phaseが持つオブジェクトを取得
	picojson::object phase = obj.get<picojson::object>();
	if (phase.count("OctreeID") == 0)return false;
	//octreeID取得
	unsigned int id = static_cast<unsigned int>(phase["OctreeID"].get<double>());
	if (phase.count("SpawnData") == 0)return false;
	//読み込むSpawnファイルの名前を取得
	std::string file = phase["SpawnData"].get<std::string>();

	_out->octreeID = static_cast<OCTREE_ID>(id);
	_out->spawnfile = file;
	return true;
}
