#pragma once
#include "../json/Picojson.h"
struct StageData;
class StageConverter
{
public:
	const bool operator()(StageData* _out, picojson::value& _value)const;
};