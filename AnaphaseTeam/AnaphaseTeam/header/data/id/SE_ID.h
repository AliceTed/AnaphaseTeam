#pragma once

#include "BGM_ID.h"

enum class SE_ID : unsigned int
{
	ENTER = static_cast<int>(BGM_ID::SIZE),
	SELECT,
	PLAYER_ATTACK,
	PLAYER_STEP,
	OPEN_SPECIALUI,
	ENEMY_ATTACK,
	ENEMY_DAMAGE,
	SIZE
};