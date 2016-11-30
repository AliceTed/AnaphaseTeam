#pragma once
#include "Type.h"

struct  LightDesc
{
	LightDesc():
		position(0,0,0),
		ambient(0,0,0,0),
		diffuse(1,1,1,1),
		specular(1,1,1,1)
	{}

	Vector3 position; //���C�g�̍��W
	Color4 ambient;   //����
	Color4 diffuse;   //�g�U���ˌ�
	Color4 specular;  //���ʔ��ˌ�
};