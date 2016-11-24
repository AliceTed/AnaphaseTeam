#include "..\..\..\header\data\loader\TextureLoader.h"
#include <gslib.h>
#include "../../../header/data/Message.h"
void TextureLoader::operator()(unsigned int _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name + _extension;
	if (!gsLoadTexture(_id, fullname.c_str()))
	{
		Message error;
		error("テクスチャの読み込みエラー",fullname);
	}
}
