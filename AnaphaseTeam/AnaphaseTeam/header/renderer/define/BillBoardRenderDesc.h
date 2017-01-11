#pragma once

#include "Type.h"
#include "ResourceID.h"
#include "BlendFunc.h"


struct BillBoardRenderDesc
{
	BillBoardRenderDesc():
		textureID(0),
		rect(0,0,0,0),
		srcRect(0,0,0,0),
		color(1,1,1,1),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}

	ResourceID textureID; //テクスチャID
	Rect rect;            //ビルボード矩形
	Rect srcRect;         //テクスチャ矩形
	Matrix4 matrix;       //変換行列
	Color4 color;         //カラー
	BlendFunc blendFunc;  //ブレンド関数

};