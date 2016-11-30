#pragma once

#include "BGM_ID.h"

enum class SE_ID : unsigned int
{
	ENTER = static_cast<int>(BGM_ID::SIZE),
	SELECT,
	SIZE
};