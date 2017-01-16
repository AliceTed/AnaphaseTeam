#include "actor/Player/Gauge.h"
#include "math/Calculate.h"
#include "data/id/TEXTURE_ID.h"
#include "renderer/define/SpriteRectRenderDesc.h"
#include <math.h>

Gauge::Gauge()
	:m_gauge(200),
	m_lerpmax(m_gauge)
{
}

Gauge::~Gauge()
{
}

void Gauge::initialize()
{
	m_gauge = 1000;
	m_lerpmax = m_gauge;
}

void Gauge::draw(IRenderer * _renderer)
{
	SpriteRectRenderDesc back;
	back.textureID = static_cast<GSuint>(TEXTURE_ID::SPGAUGE);
	back.matrix.translate(102, 100, 0);
	back.srcRect = GSrect(0,0, (int)RankGauge::MAX * 0.341f, 125);
	back.color = GScolor(0.0f, 0.0f, 1.0f, 1.0f);
	_renderer->render(back);
	
	SpriteRectRenderDesc front;
	front.textureID = static_cast<GSuint>(TEXTURE_ID::SPGAUGE);
	front.matrix.translate(102, 100, 0);
	front.srcRect = GSrect(0,0, m_gauge * 0.341f, 125);
	//front.color = GScolor(1.0f, 1.0f, 0.0f, 1.0f);
	_renderer->render(front);
}

void Gauge::up(float _scale)
{
	if (static_cast<int>(m_gauge) != static_cast<int>(m_lerpmax))
	{
		return;
	}
	add(_scale);
	m_lerpmax = m_gauge;
}

bool Gauge::down(float _scale)
{
	if (!isDown(_scale))
	{
		return false;
	}
	//add(-_scale);
	m_lerpmax = m_gauge - _scale;

	return true;
}

void Gauge::downGauge(RankGauge _rankGauge)
{
	if (m_gauge <static_cast<float>(_rankGauge))
	{
		return;
	}
	add(-static_cast<float>(_rankGauge));
}

void Gauge::update(float deltatime)
{
	m_gauge = LERP(deltatime * 0.5f, m_gauge, m_lerpmax);
}

float Gauge::scale(float def)
{
	return log(m_lerpmax*0.01f + def);
}

const bool Gauge::isDown(float _value) const
{
	if (_value > m_gauge)return false;

	return static_cast<int>(m_gauge) == static_cast<int>(m_lerpmax);
}

void Gauge::add(float _point)
{
	Math::Clamp clamp;
	m_gauge = clamp(m_gauge + _point, 0.0f, static_cast<float>(RankGauge::MAX));	
}

float Gauge::getGauge()
{
	return m_gauge;
}