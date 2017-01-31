#include "..\..\header\ui\EndingUI.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/device/GameDevice.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"

EndingUI::EndingUI()
	:m_position(0, 0, 0),
	m_change(true),
	m_count(0),
	m_still(TEXTURE_ID::PRESSKEY, GSvector2(40, 600), 0.0f),
	m_staffRoll()
{
}

EndingUI::~EndingUI()
{
}

void EndingUI::initilize()
{
	m_position = GSvector3(450, 720, 0);
	m_change = true;
	m_count = 0;
	m_still.initilize();
	m_staffRoll.initilize();
}

void EndingUI::update(float _deltaTime)
{
	m_staffRoll.update(_deltaTime);
		m_still.flashing(1.0f);
		if (GameDevice::getInstacnce().input()->jump())
		{
			m_change = false;
		}
	
	creditSkip();
	isNext();
}

void EndingUI::draw(IRenderer* _renderer)
{
	if(m_staffRoll.isEnd())
	{
		m_still.draw(_renderer);
	}
	m_staffRoll.draw(_renderer);
}

void EndingUI::creditSkip()
{
	if (GameDevice::getInstacnce().input()->jump() )
	{
		m_count += 1;
	}
	if (m_count >= 2)
	{
		m_still.flashing(1.0f);

	}
	if (m_count >= 3)
	{
		m_change = false;
	}
}

bool EndingUI::isNext()
{
	return m_change;
}

