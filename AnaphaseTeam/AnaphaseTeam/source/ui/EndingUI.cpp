#include "..\..\header\ui\EndingUI.h"
#include "../../header/data/id/TEXTURE_ID.h"
#include "../../header/device/GameDevice.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"

EndingUI::EndingUI()
	:m_position(0, 0, 0),
	m_change(true),
	m_count(0),
	m_credit(TEXTURE_ID::STAFFROLL, GSvector2(450, 720), 1.0f),
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
	m_credit.initilize();
	m_still.initilize();
	m_staffRoll.initilize();
}

void EndingUI::update(float _deltaTime)
{
	m_staffRoll.update(_deltaTime);
	if (!m_credit.scrollUp(0.0f))
	{
		m_still.flashing(1.0f);
		if (GameDevice::getInstacnce().input()->jump())
		{
			m_change = false;
		}
	}
	creditSkip();
	isNext();
}

void EndingUI::draw(IRenderer* _renderer)
{
	m_credit.draw(_renderer);
	m_still.draw(_renderer);
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
		m_credit.decrease(0.5f);
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

