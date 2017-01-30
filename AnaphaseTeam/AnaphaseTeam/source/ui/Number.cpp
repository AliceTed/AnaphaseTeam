#include "../../header/ui/Number.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"
#include "../../header/renderer/define/SpriteRectRenderDesc.h"
#include "../../header/ui/alpha.h"

#include <sstream>
#include <string>

#include <cstdlib>
#include <iostream>
#include <typeinfo>

Number::Number(TEXTURE_ID _id)
	:m_id(_id),
	m_position(0,0),
	m_alpha(0.0f),
	m_alphaChange(true)
{
}

Number::~Number()
{
}

void Number::initilize()
{
	reset();
}

void Number::scroll()
{
	if (m_position.x <= 1030)
	{
		m_position.x += 60;
		return;
	}
}

void Number::update(float deltaTime)
{
	if (m_alpha < 0.0f)
	{
		reset();
	}
}

void Number::flashing(float _addTime, float _decTime)
{
	if (m_alphaChange)
	{
		if (m_alpha <= 1)
		{
			m_alpha += 1 / (60 * _addTime);
		}

		if (m_alpha >= 1)
		{
			m_alphaChange = false;
		}

	}

	if (!m_alphaChange)
	{
		if (m_alpha > 0)
		{
			m_alpha -= 1 / (60 * _decTime);
		}
	}
}

void Number::draw(IRenderer * _renderer, int _nunber)
{
	NumberSpriteRenderDesc desc;
	desc.decimal = 0;
	desc.digit = 1;
	desc.size = GSvector2(40*1.5, 62*1.5);
	desc.number = _nunber;
	desc.color.a = m_alpha;
	desc.matrix.translate(m_position);
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::SMALL_NUMBER);
	_renderer->render(desc);

}

void Number::reset()
{
	m_alpha = 0.0f;
	m_position = GSvector2(550, 250);
	m_alphaChange = true;
}
