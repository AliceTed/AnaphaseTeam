#pragma once
#ifndef _PATHCONNECT_H_
#define _PATHCONNECT_H_
#include <string>
namespace Data
{
	class PathConnect
	{
	public:
		const char* operator ()(const std::string& name, const std::string& path, const std::string& extension)
		{
			std::string fullpath = path + name + extension;
			return fullpath.c_str();
		}
	};
}

#endif // !_PATHCONNECT_H_
