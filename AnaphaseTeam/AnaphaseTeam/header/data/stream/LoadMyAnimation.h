#pragma once
#include <string>
#include <vector>
class MyAnimation;
class LoadMyAnimation
{
public:
	const bool operator ()(unsigned int _id, const std::string& _file, const std::string& _extension=".myanim")const;
};