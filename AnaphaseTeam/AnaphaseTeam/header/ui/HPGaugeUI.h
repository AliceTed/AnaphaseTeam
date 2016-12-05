#pragma once
#include <gslib.h>
#include "IPlayUI.h"

class Status;
class HPGaugeUI :public IPlayUI
{
public:
	HPGaugeUI(const GSvector2& _posistion,Status& _status);
	// IPlayUI ����Čp������܂���
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
private:
	GSvector2 m_posistion;
	Status& m_status;
	float m_maxHelth;
	static const float MAGNI;
};