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
	ResourceID octreeID; //�I�N�c���[ID
	Matrix4 matrix;    //�ϊ��s��
	Color4 color;      //�J���[
	BlendFunc blendFunc;//�u�����h�֐�
};