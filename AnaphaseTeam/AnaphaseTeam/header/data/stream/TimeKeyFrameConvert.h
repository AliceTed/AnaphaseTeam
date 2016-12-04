#pragma once
#include <string>
struct TimeKeyFrame;
class TimeKeyFrameConvert
{
public:
	const bool operator()(TimeKeyFrame* _out, const std::string& _data)const;
};
