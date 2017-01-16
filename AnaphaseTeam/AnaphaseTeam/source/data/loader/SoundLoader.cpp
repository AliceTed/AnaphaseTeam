#include "..\..\..\header\data\loader\SoundLoader.h"
#include <GSmusic.h>
#include "data/Message.h"
void SoundLoader::operator()(unsigned int _id, const std::string & _name, bool _isLoop, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name + _extension;
	if (!gsLoadMusic(_id, fullname.c_str(),_isLoop))
	{
		Message error;
		error("サウンドの読み込みエラー", fullname);
	}
}
