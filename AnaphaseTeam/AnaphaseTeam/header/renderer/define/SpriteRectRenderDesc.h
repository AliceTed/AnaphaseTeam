#pragma once
#include "Type.h"
#include "ResourceID.h"
#include "BlendFunc.h"
struct SpriteRectRenderDesc
{
	SpriteRectRenderDesc() :
		textureID(0),
		srcRect(0, 0, 0, 0),
		center(0, 0),
		color(1, 1, 1, 1),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}

	ResourceID textureID;
	Rect srcRect;
	Vector2 center;
	Matrix4 matrix;
	Color4 color;
	BlendFunc blendFunc;
};