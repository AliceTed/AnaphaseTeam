pragma once

#include "ResourceID.h"
#include "Rect.h"
#include "Matrix4.h"
#include "Color4.h"
#include "BlendFunc.h"

//�r���{�[�h�`��L�q�q
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

	ResourceID textureID;//�e�N�X�`��ID
	Rect rect;           //�r���{�[�h�̋�`
	Rect srcRect;        //�e�N�X�`���̋�`
	Matrix4 matrix;      //�ϊ��s��
	Color4 color;        //�J���[
	BlendFunc blendFunc; //�u�����h�֐�
};