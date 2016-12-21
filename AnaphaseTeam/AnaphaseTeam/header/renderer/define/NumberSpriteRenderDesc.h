#pragma once
#include "Type.h"
#include "ResourceID.h"
#include "BlendFunc.h"
struct NumberSpriteRenderDesc
{
	NumberSpriteRenderDesc()
		:textureID(0),
		center(0.0f,0.0f),
		matrix(),
		color(1.0f,1.0f,1.0f,1.0f),
		blendFunc(BlendFunc::DEFAULT),
		size(32,64),
		decimal(1),
		digit(3),
		number(0.0f)
	{
		matrix.identity();
	}
	ResourceID textureID;
	Vector2 center;
	Matrix4 matrix;
	Color4 color;
	BlendFunc blendFunc;

	//�؂���T�C�Y
	Vector2 size;
	//�����_�̐�
	GSuint decimal;
   //�\�����錅��(�����_���܂�)
	GSuint digit;
	//�`�悷�鐔��
	float number;

};