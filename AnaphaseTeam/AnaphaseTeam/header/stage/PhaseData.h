#pragma once
#include <string>
#include <GSvector3.h>
#include "../data/id/OCTREE_ID.h"
struct PhaseData
{
	std::string spawn;
	OCTREE_ID octreeID;
	GSvector3 octreeOffset;
};