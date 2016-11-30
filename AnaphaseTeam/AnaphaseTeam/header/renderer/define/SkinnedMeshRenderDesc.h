#pragma once
#include "Type.h"
#include "ResourceID.h"
struct SkinnedMeshRenderDesc
{
	SkinnedMeshRenderDesc() :
		meshID(0),
		shaderID(0),
		animation(nullptr)
	{
		matrix.identity();
	}
	ResourceID meshID; //���b�V��ID
	ResourceID shaderID;//�V�F�[�_ID
	Matrix4 matrix;    //�ϊ��s��
	Matrix4* animation;//�A�j���[�V�����s��
};