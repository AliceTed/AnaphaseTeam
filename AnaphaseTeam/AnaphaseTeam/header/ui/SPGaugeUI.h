#pragma once
#include "IPlayUI.h"
class Gauge;
class SPGaugeUI :public IPlayUI
{
public:
	SPGaugeUI(Gauge &_gauge);
	~SPGaugeUI();
	void update(float deltaTime);
	void draw(IRenderer *_renderer);
private:
	Gauge& m_gauge;
};