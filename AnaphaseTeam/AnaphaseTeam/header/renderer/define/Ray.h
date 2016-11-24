#pragma once

#include "Type.h"

struct Ray
{
	Ray()://デフォルトコンストラクタ
		position(0,0,0),
		direction(0,0,0)
	{}

	Ray( const Vector3& pos, const Vector3& dir):
		position(pos),
		direction(dir)
	{}

	Vector3 position; //座標
	Vector3 direction;//方向
};
