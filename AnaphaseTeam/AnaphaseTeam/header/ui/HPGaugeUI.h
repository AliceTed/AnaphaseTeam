#pragma once
#include "IPlayUI.h"
class Status;
class HPGaugeUI :public IPlayUI
{
public:
	HPGaugeUI(Status& _status);
	~HPGaugeUI();
	// IPlayUI ����Čp������܂���
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
private:
	Status& m_status;
	float m_maxHelth;
	static const float MAGNI;
};