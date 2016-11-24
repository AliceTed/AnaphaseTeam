#pragma once

#include "Matrix4.h"
#include "Color4.h"
#include "ResourceID.h"
#include "BlendFunc.h"

//���b�V���`��L�q�q
struct MeshRenderDesc
{
	MeshRenderDesc():
		meshID(0),
		color(1,1,1,1),
		blendFunc(BlendFunc::DEFAULT)
	{
		matrix.identity();
	}

	ResourceID meshID;//���b�V��ID
	Matrix4 matrix;//�ϊ��s��
	Color4 color;//�J���[
	BlendFunc blendFunc;//�u�����h�֐�

};