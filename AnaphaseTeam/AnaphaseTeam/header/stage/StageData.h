#pragma once
#include <vector>
#include <string>
#include "../transform/Transform.h"
#include "PhaseData.h"
struct StageData
{
	StageData()
		:init(),
		pahseData()
	{
	}
	Transform init;
	std::vector<std::string> pahseData;
};