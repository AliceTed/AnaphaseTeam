#pragma once

#include <string>
#include "StatusParameter.h"

using namespace std;

struct LoadStatus
{
	string selfID;
	StatusParameter parameter;

	LoadStatus() :
		selfID(""),
		parameter()
	{}
};