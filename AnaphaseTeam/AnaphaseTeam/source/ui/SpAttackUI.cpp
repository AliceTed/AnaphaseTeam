#include "../../header/ui/SpAttackUI.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/device/GameDevice.h"

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
	if (GameDevice::getInstacnce().input()->specialSkillMode())
	{
		if (m_ID == TEXTURE_ID::SP_UI)
		{
			m_scale = GSvector2(1, 1);
		}
	}

	if (!GameDevice::getInstacnce().input()->specialSkillMode())
	{
		m_scale = GSvector2(0.6, 0.6);
	}
}

void SpAttackUI::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID =static_cast<GSuint>(m_ID);
	desc.matrix.scale(m_scale);
	desc.matrix.translate(1000,500, 0);
	_renderer->render(desc);
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


