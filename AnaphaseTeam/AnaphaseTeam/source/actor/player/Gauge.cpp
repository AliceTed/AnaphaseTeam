#include "..\..\..\header\actor\Player\Gauge.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/data/TEXTURE_ID.h"
#include <math.h>

Gauge::Gauge()
	:m_gauge(150),
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

void Gauge::draw(const Renderer& _renderer)
{
	_renderer.getDraw2D().string(std::to_string((int)m_gauge), &GSvector2(0, 50), 50);
	_renderer.getDraw2D().textrue(TEXTURE_ID::BLACK, &GSvector2(0,0), &GSrect(0,0,(int)RankGauge::MAX,30),&GSvector2(0,0),&GSvector2(1,1),0.0f);
	_renderer.getDraw2D().textrue(TEXTURE_ID::CLEAR, &GSvector2(0, 0), &GSrect(0, 0, m_gauge, 30), &GSvector2(0, 0), &GSvector2(1, 1),0.0f,&GScolor(0.0f,1.0f,0.0f,1.0f));
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
	if (_scale > m_gauge)
	{
		return false;
	}
	if (static_cast<int>(m_gauge) != static_cast<int>(m_lerpmax))
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
	lerp(&m_gauge, &m_gauge, &m_lerpmax, deltatime * 0.1f);
}

float Gauge::scale(float def)
{
	return log(m_lerpmax*0.01f + def);
}

float Gauge::nowGauge()
{
	return m_gauge;
}

void Gauge::add(float _point)
{
	Math::Clamp clamp;
	m_gauge = clamp(m_gauge + _point, 0.0f, static_cast<float>(RankGauge::MAX));
	
}

void Gauge::lerp(float * out, const float * min, const float * max, float time)
{
	*out = LERP(time, *min, *max);
}
