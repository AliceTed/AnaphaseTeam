#pragma once
#include <gslib.h>
#include "IPlayUI.h"

class Status;
class HPGaugeUI :public IPlayUI
{
public:
	HPGaugeUI(const GSvector2& _posistion,Status& _status,float _scale=10.0f);
	// IPlayUI ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
private:
	GSvector2 m_posistion;
	Status& m_status;
	const float m_scale;
};