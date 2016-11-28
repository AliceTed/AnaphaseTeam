#pragma once

#include "BGM_ID.h"

enum class SE_ID : unsigned int
{
	TITLE = static_cast<int>(BGM_ID::SIZE) + 1,
	SIZE
};