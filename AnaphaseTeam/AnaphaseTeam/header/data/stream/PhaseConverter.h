#pragma once
#include "../json/Picojson.h"
struct PhaseData;
class PhaseConverter
{
public:
	const bool operator()(PhaseData* _out,picojson::value& _value)const;
};