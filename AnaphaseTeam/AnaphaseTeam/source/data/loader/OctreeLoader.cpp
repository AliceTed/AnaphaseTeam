#include "..\..\..\header\data\loader\OctreeLoader.h"
#include <gslib.h>
#include "../../../header/data/Message.h"
void OctreeLoader::operator()(unsigned int _id, const std::string & _name, bool _isShader, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name + _extension;
	if (!load(_id,fullname,_isShader))
	{
		Message error;
		error("オクツリーの読み込みエラー", fullname);
	}
}

const bool OctreeLoader::load(unsigned int _id, const std::string & _fullname, bool _isShader)
{
	if (_isShader)
	{
		return gsLoadOctreeEx(_id, _fullname.c_str())==GS_TRUE;
	}
	return gsLoadOctree(_id, _fullname.c_str()) == GS_TRUE;
}
