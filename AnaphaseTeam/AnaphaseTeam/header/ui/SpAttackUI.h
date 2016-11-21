#pragma once
#include <gslib.h>
#include "../data/TEXTURE_ID.h"
#include "../../header/device/Input.h"

class Renderer;

class SpAttackUI
{
public:
	SpAttackUI();
	~SpAttackUI();
	void initilize();
	void update();
	void draw(const Renderer& _renderer);
	void spChange(TEXTURE_ID _ID);
	void resetID();
private:
	TEXTURE_ID m_ID;
	int m_Time;
	Input m_input;
    GSvector2 m_scale;
};