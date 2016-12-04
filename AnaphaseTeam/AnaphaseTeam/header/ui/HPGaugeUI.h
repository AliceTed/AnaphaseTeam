#pragma once
#include "IPlayUI.h"
class Status;
class HPGaugeUI :public IPlayUI
{
public:
	HPGaugeUI(Status& _status);
	~HPGaugeUI();
	// IPlayUI を介して継承されました
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
private:
	Status& m_status;
	float m_maxHelth;
	static const float MAGNI;
};