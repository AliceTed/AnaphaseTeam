#pragma once
#include"Type.h"
#include"BlendFunc.h"

struct RectangleRenderDesc
{
	RectangleRenderDesc():
		rect(0,0,0,0),
		color(1,1,1,1),
		blendFunc(BlendFunc::DEFAULT)
	{}

	Rect rect; //��`�T�C�Y
	Color4 color;//�J���[
	BlendFunc blendFunc;//�u�����h�֐�
};