#pragma once

struct ViewportDesc
{
	ViewportDesc():
		x(0), y(0),
		width(1),
		height(1)
	{}

	int x;    //x���W
	int y;    //y���W 
	int width;//��
	int height;//����
};