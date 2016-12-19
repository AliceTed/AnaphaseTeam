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
	}
	ResourceID octreeID; //オクツリーID
	Color4 color;      //カラー
	BlendFunc blendFunc;//ブレンド関数
};