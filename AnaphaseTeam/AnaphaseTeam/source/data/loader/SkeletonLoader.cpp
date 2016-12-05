#include "..\..\..\header\data\loader\SkeletonLoader.h"
#include <gslib.h>
#include "../../../header/data/Message.h"
void SkeletonLoader::operator()(unsigned int _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name + _extension;
	if (!gsLoadSkeleton(_id, fullname.c_str()))
	{
		Message error;
		error("スケルトンの読み込みエラー", fullname);
	}
}
