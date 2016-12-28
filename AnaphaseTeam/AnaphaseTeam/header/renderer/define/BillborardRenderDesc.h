pragma once

#include "ResourceID.h"
#include "Rect.h"
#include "Matrix4.h"
#include "Color4.h"
#include "BlendFunc.h"

//ビルボード描画記述子
struct BillboardRenderDesc
{
	BillboardRenderDesc():
		textureID(0),
		rect(0,0,0,0),
		srcRect(0,0,0,0),
		color(1,1,1,1),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}

	ResourceID textureID;//テクスチャID
	Rect rect;           //ビルボードの矩形
	Rect srcRect;        //テクスチャの矩形
	Matrix4 matrix;      //変換行列
	Color4 color;        //カラー
	BlendFunc blendFunc; //ブレンド関数
};