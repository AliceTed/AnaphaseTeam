#pragma once
#include "Type.h"
#include "ResourceID.h"
#include "BlendFunc.h"
struct AnimationRenderDesc
{
	AnimationRenderDesc() :
		meshID(0),
		color(1, 1, 1, 1),
		blendFunc(BlendFunc::DEFAULT),
		animation(nullptr)
	{
		matrix.identity();
	}
	ResourceID meshID; //���b�V��ID
	Matrix4 matrix;    //�ϊ��s��
	Matrix4* animation;//�A�j���[�V�����s��
	Color4 color;      //�J���[
	BlendFunc blendFunc;//�u�����h�֐�
};