#include "..\..\header\ui\alpha.h"
#include "../../header/renderer/IRenderer.h"
#include "../../header/renderer/define/SpriteRenderDesc.h"

alpha::alpha(TEXTURE_ID _ID, GSvector2 _position, float _alpha)
	:m_textureID(_ID),
	m_currentPosition(_position),
	m_value(0.0f),
	m_alpha(_alpha),
	m_change(false),
	m_position(0, 0),
	m_currentAlpha(0.0f)

{
}

alpha::~alpha()
{
}

void alpha::initilize()
{
	m_position = m_currentPosition;
	m_value = 0.0f;
	m_currentAlpha = m_alpha;
	m_change = false;
}

void alpha::update()
{

}

void alpha::draw(IRenderer * _renderer)
{
	SpriteRenderDesc desc;
	desc.textureID = static_cast<GSuint>(m_textureID);
	desc.matrix.translate(m_position);
	desc.color.a = m_currentAlpha;

	_renderer->render(desc);

}

void alpha::decrease(float _time)
{
	//Œ¸­
	m_value = 1 / (_time * 60);
	if (m_currentAlpha >= 0.0f)
	{
		m_currentAlpha -= m_value;
	}
}

void alpha::increase(float _time)
{
	//‰ÁŽZ
	m_value = 1 / (_time * 60);
	if (m_currentAlpha <= 1.0f)
	{
		m_currentAlpha += m_value;
	}
}

void alpha::flashing(float _time)
{
	if (m_change)
	{
		decrease(_time);
		if (m_currentAlpha < 0)
		{
			m_change = false;
		}
	}
	if (!m_change)
	{
		increase(_time);
		if (m_currentAlpha > 1.0f)
		{
			m_change = true;
		}
	}
}

bool alpha::up(float _position)
{
	m_position.y -= 2;
	if (m_position.y > _position)
	{
		return true;
	}
	return false;
}

bool alpha::down(float _position)
{
	return true;
}
