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

Number::Number(TEXTURE_ID _id, const GSvector2 & _position)
	:m_id(_id),
	m_position(_position),
	m_alpha(0.0f)
{
}

Number::~Number()
{
}

void Number::initilize()
{
	m_alpha = 0.0f;
}

void Number::start()
{
	m_alpha = 1.0f;
}

void Number::update(float deltaTime)
{
	if (m_alpha <= 0.0f)
	{
		alphaReset();
	}
}

void Number::decrease(float _time)
{
	m_alpha -= 1 / (60 * _time);
}

std::string Number::intToString(int _number)
{
	std::stringstream ss;
	ss << _number;
	return ss.str();
}


void Number::draw(IRenderer * _renderer, int _nunber)
{
	SpriteRectRenderDesc desc;
	GSvector2 pos;
	pos = m_position;
	for each(auto n in intToString(_nunber))
	{
		desc.srcRect = Rect(static_cast<int>(n) * 32, 0, (static_cast<int>(n) * 32) + 32, 64);
		//desc.srcRect = GSrect(static_cast<int>(n - '0') * 32, 0, (static_cast<int>(n) * 32) + 32, 64);
		desc.color.a = m_alpha;
		desc.matrix.translate(pos);
		desc.textureID = static_cast<GSuint>(m_id);
		_renderer->render(desc);
		//pos.x -= 268;
		//pos.y -= 300;
	}

}

void Number::drawNum(IRenderer * _renderer, int _nunber, int x, int y)
{
	static GSvector2 m_pos;
	static GSrect rect = { 0,0,64,64 };
	SpriteRectRenderDesc desc;

	for each(auto n in intToString(_nunber))
	{
		m_pos.x = x;
		m_pos.y = y;
		rect.left = static_cast<int>(n) * 32;
		rect.right = rect.left + 32;
		rect.top = 0;
		rect.bottom = 64;
		desc.srcRect = GSrect(rect);
		desc.color.a = m_alpha;
		desc.matrix.translate(m_pos);
		desc.textureID = static_cast<GSuint>(m_id);
		_renderer->render(desc);
	}
}

void Number::alphaReset()
{
	m_alpha = 0.0f;
}
