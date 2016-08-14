#pragma once
#ifndef _PATHCONNECT_H_
#define _PATHCONNECT_H_
#include <string>
namespace Data
{
	class PathConnect
	{
	public:
		//const char* ‚ð•Ô‚·‚Æ•¶Žš‰»‚¯‚·‚é
		const std::string operator ()(const std::string& name, const std::string& path, const std::string& extension)const
		{
			std::string fullpath = path + name + extension;
			return fullpath;
		}
	};
}

#endif // !_PATHCONNECT_H_
