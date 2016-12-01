#pragma once
#include "Type.h"
#include "ResourceID.h"
#include "BlendFunc.h"
struct SkyBoxRenderDesc
{
	SkyBoxRenderDesc() :
		meshID(0),
		color(1, 1, 1, 1),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}
	ResourceID meshID; //メッシュID
	Matrix4 matrix;    //変換行列
	Color4 color;      //カラー
	BlendFunc blendFunc;//ブレンド関数
};