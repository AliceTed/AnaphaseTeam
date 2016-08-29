#pragma once

#include "MESH_ID.h"
enum class MODEL_ID :unsigned int
{
	PLAYER=static_cast<unsigned int>(MESH_ID::SIZE),
	KARATE,
	SIZE
};