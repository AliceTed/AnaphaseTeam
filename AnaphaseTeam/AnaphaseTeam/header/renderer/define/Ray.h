#pragma once

#include "Type.h"

struct Ray
{
	Ray()://�f�t�H���g�R���X�g���N�^
		position(0,0,0),
		direction(0,0,0)
	{}

	Ray( const Vector3& pos, const Vector3& dir):
		position(pos),
		direction(dir)
	{}

	Vector3 position; //���W
	Vector3 direction;//����
};
