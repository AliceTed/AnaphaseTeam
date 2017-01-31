#include "../../../header/actor/Player/Gauge.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/data/id/TEXTURE_ID.h"
#include "../../../header/renderer/define/SpriteRectRenderDesc.h"
#include <math.h>

Gauge::Gauge()
	:m_gauge(150),
	m_lerpmax(m_gauge),
	m_increaseGauge(0)
{
}

Gauge::~Gauge()
{
}

void Gauge::initialize()
{
	//m_gauge = 150;
	m_lerpmax = m_gauge;
}

void Gauge::draw(IRenderer * _renderer)
{
	const int width = 123;
	const int height = 119;
	int max = static_cast<int>(RankGauge::MAX);
	SpriteRectRenderDesc front;
	front.textureID = static_cast<GSuint>(TEXTURE_ID::SPECIAL_GAUGE);
	float percent = (max - m_gauge) / max * height;
	front.srcRect = GSrect(0, percent, width, height);
	front.matrix.translate(1113, 15 + percent, 0);

	_renderer->render(front);
}

void Gauge::up(float _scale)
{
	if (static_cast<int>(m_gauge) != static_cast<int>(m_lerpmax))
	{
		return;
	}
	add(_scale * m_increaseGauge);
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
	m_gauge =Math::Calculate::clamp(m_gauge + _point, 0.0f, static_cast<float>(RankGauge::MAX));	
}

/*void Gauge::add(int _point = 1)
{
	Math::Clamp clamp;
	m_gauge = clamp(m_gauge + DEFULT * _POINT, 0.0f, static_cast<float>(RankGauge::MAX));
}*/


float Gauge::getGauge()
{
	return m_gauge;
}