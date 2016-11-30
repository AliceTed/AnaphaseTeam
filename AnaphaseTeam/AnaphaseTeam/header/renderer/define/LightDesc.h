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

	Vector3 position; //ƒ‰ƒCƒg‚ÌÀ•W
	Color4 ambient;   //ŠÂ‹«Œõ
	Color4 diffuse;   //ŠgU”½ËŒõ
	Color4 specular;  //‹¾–Ê”½ËŒõ
};