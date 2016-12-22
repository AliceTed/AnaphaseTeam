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

Number::Number(TEXTURE_ID _id, const GSvector2& _position)
	:m_id(_id),
	m_position(_position),
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
	if (m_position.x < 200)
	{
		m_position.x += 30;
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
	//0Ç…Ç∑ÇÍÇŒè≠êîï\é¶ÇµÇ»Ç¢
	desc.decimal = 0;
	desc.number = _nunber;
	desc.color.a = m_alpha;
	desc.matrix.translate(m_position);
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::NUMBER);
	_renderer->render(desc);

}

void Number::reset()
{
	m_alpha = 0.0f;
	m_position = GSvector2(0, 0);
	m_alphaChange = true;
}
