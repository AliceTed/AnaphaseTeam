#pragma once
#include <memory>
#include <gslib.h>
#include "SHAPE_TYPE.h"
class Shape;
struct ShapeData
{
	float spawnTime;
	float destroyTime;
	SHAPE_TYPE type;
	std::shared_ptr<Shape>shape;
	GSvector3 offset;
};
