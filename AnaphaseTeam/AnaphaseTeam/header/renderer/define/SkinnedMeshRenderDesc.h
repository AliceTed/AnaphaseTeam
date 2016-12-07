#pragma once
#include "Type.h"
#include "ResourceID.h"
struct SkinnedMeshRenderDesc
{
	SkinnedMeshRenderDesc() :
		meshID(0),
		shaderID(0),
		animation(nullptr),
		color(1.0f, 1.0f, 1.0f, 1.0f)
	{
		matrix.identity();
	}
	ResourceID meshID; //メッシュID
	ResourceID shaderID;//シェーダID
	Matrix4 matrix;    //変換行列
	Matrix4* animation;//アニメーション行列
	GScolor color;
};