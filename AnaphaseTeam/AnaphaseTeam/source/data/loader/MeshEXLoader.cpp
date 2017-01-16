#include "..\..\..\header\data\loader\MeshEXLoader.h"
#include <gslib.h>
#include "data/Message.h"
void MeshEXLoader::operator()(unsigned int _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name + _extension;
	if (!gsLoadMeshEx(_id, fullname.c_str()))
	{
		Message error;
		error("メッシュEXの読み込みエラー", fullname);
	}
}
