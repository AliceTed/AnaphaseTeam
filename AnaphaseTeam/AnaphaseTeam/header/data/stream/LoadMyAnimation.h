#pragma once
#include <string>
#include <vector>
class MyAnimation;
class LoadMyAnimation
{
public:
	const bool operator ()(unsigned int _id, const std::string& _file, const std::string& _extension=".myanim")const;
private:
	const bool add(MyAnimation* _out,const std::vector<float>& _f_data)const;
	//float配列の要素数がtargetと同じか
	const bool isJustCount(unsigned int _size,unsigned int _target)const;
};