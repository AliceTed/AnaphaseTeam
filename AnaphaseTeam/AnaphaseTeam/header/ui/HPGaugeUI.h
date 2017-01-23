#pragma once
#include <gslib.h>
#include "IPlayUI.h"
#include "../data/id/TEXTURE_ID.h"

class Status;
class HPGaugeUI :public IPlayUI
{
public:
	HPGaugeUI(const GSvector2& _posistion,Status& _status, TEXTURE_ID _hpID, TEXTURE_ID _hpGaugeID, float _scale = 3.41f);
	// IPlayUI ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	void update(float deltaTime);
	void draw(IRenderer * _renderer);
private:
	GSvector2 m_posistion;
	Status& m_status;
	const float m_scale;
	const TEXTURE_ID m_hpID;
	const TEXTURE_ID m_hpGaugeID;

};