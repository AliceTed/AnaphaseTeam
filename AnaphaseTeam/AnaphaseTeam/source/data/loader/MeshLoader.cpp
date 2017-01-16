#include "..\..\..\header\data\loader\MeshLoader.h"
#include <gslib.h>
#include "data/Message.h"
void MeshLoader::operator()(unsigned int _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name + _extension;
	if (!gsLoadMesh(_id, fullname.c_str()))
	{
		Message error;
		error("メッシュの読み込みエラー", fullname);
	}
}
