#pragma once
#include "Type.h"
#include "ResourceID.h"
#include "BlendFunc.h"
struct OctreeRenderDesc
{
	OctreeRenderDesc() :
		octreeID(0),
		color(1, 1, 1, 1),
		blendFunc(BlendFunc::DEFAULT)
	{
	}
	ResourceID octreeID; //�I�N�c���[ID
	Color4 color;      //�J���[
	BlendFunc blendFunc;//�u�����h�֐�
};