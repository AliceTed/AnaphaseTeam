#include "../../header/ui/SpAttackUI.h"
#include "../../header/data/TEXTURE_ID.h"
#include "../../header/renderer/Renderer.h"

SpAttackUI::SpAttackUI()
	:m_ID(TEXTURE_ID::SP_UI)
	,m_Time(0)
	,m_scale(0.6,0.6)
{}

SpAttackUI::~SpAttackUI()
{
}

void SpAttackUI::initilize()
{
	m_ID = TEXTURE_ID::SP_UI;
	m_Time = 0;
}

void SpAttackUI::update()
{
	resetID();
	if (m_input.spState())
	{
		if (m_ID == TEXTURE_ID::SP_UI)
		{
			m_scale = GSvector2(1, 1);
		}
	}

	if (!m_input.spState())
	{
		if (m_ID == TEXTURE_ID::SP_UI)
		{
			m_scale = GSvector2(0.6, 0.6);
		}
	}

}

void SpAttackUI::draw(const Renderer& _renderer)
{
	//_renderer.getDraw2D().textrue(m_ID,&GSvector2(30, 30),&GSvector2(0,0),&GScolor(0,0,0,0));
	_renderer.getDraw2D().textrue(m_ID, &GSvector2(250, 250),NULL,&GSvector2(250,250),&m_scale,0);
}

void SpAttackUI::spChange(TEXTURE_ID _ID)
{
	m_ID = _ID;
}

void SpAttackUI::resetID()
{
	if (m_ID != TEXTURE_ID::SP_UI)
	{
		m_Time++;
		if (m_Time > 60)
		{
			m_ID = TEXTURE_ID::SP_UI;
			m_Time = 0;
		}
	}
}

