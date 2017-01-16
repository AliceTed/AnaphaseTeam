#include "..\..\..\header\data\loader\MyAnimationLoader.h"
#include "data/Message.h"
#include "data/stream/LoadMyAnimation.h"

void MyAnimationLoader::operator()(unsigned int _id, const std::string & _name, const std::string & _path, const std::string & _extension)
{
	std::string fullname = _path + _name;
	LoadMyAnimation load;
	if (!load(_id, fullname, _extension))
	{
		Message error;
		error("MyAnimation‚Ì“Ç‚İ‚İƒGƒ‰[", fullname + _extension);
	}
}
