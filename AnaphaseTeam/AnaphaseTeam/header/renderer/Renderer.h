#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "Draw2D.h"
#include "Draw3D.h"
//‚Æ‚è‚ ‚¦‚¸
class Renderer
{
public:
	Renderer();
	const Draw2D& getDraw2D()const;
	const Draw3D& getDraw3D()const;
private:
	Draw2D m_Draw2D;
	Draw3D m_Draw3D;
};
#endif