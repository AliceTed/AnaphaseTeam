#pragma once

struct ViewportDesc
{
	ViewportDesc():
		x(0), y(0),
		width(1),
		height(1)
	{}

	int x;    //x座標
	int y;    //y座標 
	int width;//幅
	int height;//高さ
};