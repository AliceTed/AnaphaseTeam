#pragma once

#include "Matrix4.h"
#include "Color4.h"
#include "ResourceID.h"
#include "BlendFunc.h"

//メッシュ描画記述子
struct MeshRenderDesc
{
	MeshRenderDesc():
		meshID(0),
		color(1,1,1,1),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}

	ResourceID meshID;//メッシュID
	Matrix4 matrix;//変換行列
	Color4 color;//カラー
	BlendFunc blendFunc;//ブレンド関数

};