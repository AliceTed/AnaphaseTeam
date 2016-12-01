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
	ResourceID meshID; //���b�V��ID
	Matrix4 matrix;    //�ϊ��s��
	Color4 color;      //�J���[
	BlendFunc blendFunc;//�u�����h�֐�
};