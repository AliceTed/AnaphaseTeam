#include "..\..\..\header\data\loader\AnimationLoader.h"
#include <gslib.h>
#include "../../../header/data/Message.h"
void AnimationLoader::operator()(unsigned int _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name + _extension;
	if (!gsLoadAnimation(_id, fullname.c_str()))
	{
		Message error;
		error("アニメーションの読み込みエラー", fullname);
	}
}
