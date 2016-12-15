#pragma once
#include <string>
#include "AttackStatus.h"
#include "ShapeData.h"
struct AttackParameter
{
	AttackStatus status;
	unsigned int animationID;
	std::string slowID;
	std::string quickID;
	ShapeData shapeData;
};