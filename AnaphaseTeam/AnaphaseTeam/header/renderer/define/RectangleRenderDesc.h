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

	Rect rect; //矩形サイズ
	Color4 color;//カラー
	BlendFunc blendFunc;//ブレンド関数
};