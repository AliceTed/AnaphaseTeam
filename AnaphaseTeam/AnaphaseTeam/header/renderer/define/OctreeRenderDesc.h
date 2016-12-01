#pragma once
#include "Type.h"
#include "ResourceID.h"
#include "BlendFunc.h"
struct OctreeRenderDesc
{
	OctreeRenderDesc() :
		octreeID(0),
		color(1, 1, 1, 1),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}
	ResourceID octreeID; //オクツリーID
	Matrix4 matrix;    //変換行列
	Color4 color;      //カラー
	BlendFunc blendFunc;//ブレンド関数
};