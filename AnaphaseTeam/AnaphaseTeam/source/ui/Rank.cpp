#include "../header/ui/Rank.h"
#include "renderer/define/SpriteRectRenderDesc.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "renderer/IRenderer.h"

Rank::Rank()
	:m_alpha(0.0f),
	m_rank(RANK::D),
	m_timer(1),
	m_add(1),
	m_isDraw(false)
{
}

Rank::~Rank()
{
}

void Rank::initilize()
{
	m_rank = RANK::D;
	m_alpha = 0.0f;
	m_timer.initialize();
	m_add = 0.1;
	m_isDraw = false;
}

void Rank::update(float _deltaTime)
{
	m_alpha = CLAMP(m_alpha + m_add * _deltaTime, 0, 1.0f);
	if (m_alpha >= 1.0f)
	{
		m_add *= -1.0f;
		m_isDraw = true;
	}

	m_timer.update(_deltaTime);
}

void Rank::draw(IRenderer * _renderer)
{
	if (m_isDraw)
	{
		SpriteRectRenderDesc scoreDesc;
		scoreDesc.matrix.translate(GSvector3(280, 160, 0));
		scoreDesc.srcRect = getCut();
		scoreDesc.textureID = static_cast<GSuint>(TEXTURE_ID::RANK);
		_renderer->render(scoreDesc);
	}

	SpriteRenderDesc desc;
	desc.color.a = m_alpha;
	desc.textureID = static_cast<GSuint>(TEXTURE_ID::WHITE);
	_renderer->render(desc);
}

void Rank::calc_Rank(int _score)
{
	m_rank = calc(_score);
}

bool Rank::isDead()
{
	return m_isDraw;
}

Rank::RANK Rank::calc(int _score) const
{
	const RANK rank[] = { RANK::S,RANK::A,RANK::B,RANK::C,RANK::D };
	for (auto i : rank)
	{
		if (static_cast<int>(i) <= _score)return i;
	}
	return RANK::D;
}

GSrect Rank::getCut() const
{
	const float width = 370.0f;
	const float height = 435.0f;
	const int  length = 5;
	const RANK rank[length] = { RANK::S,RANK::A,RANK::B,RANK::C,RANK::D };
	for (int i = 0; i < length; i++)
	{
		if (rank[i] == m_rank)
		{
			float left = width * i;
			return GSrect(left, 0, left + width, height);
		}
	}
	return GSrect();
}
