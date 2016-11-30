#pragma once
#include <gslib.h>
#include "../data/id/TEXTURE_ID.h"
#include "../../header/device/Input.h"

class IRenderer;

class SpAttackUI
{
public:
	SpAttackUI();
	~SpAttackUI();
	void initilize();
	void update();
	void draw(IRenderer * _renderer);
	void spChange(TEXTURE_ID _ID);
	void resetID();
private:
	TEXTURE_ID m_ID;
	int m_Time;
    GSvector2 m_scale;
};