#include "..\..\..\header\actor\Player\Gauge.h"
#include "../../../header/math/Calculate.h"
#include "../../../header/data/TEXTURE_ID.h"
#include <math.h>



const float Gauge::MAXGAUGE = 100.0f;
const float Gauge::MINGAUGE = 0.0f;
const float Gauge::ONEGAUGE = 33.0f;

Gauge::Gauge()
	:m_gauge(ONEGAUGE),
	m_RankGauge(RankGauge::FIRST)
{
	rankvector.emplace_back(RankGauge::ZERO);
	rankvector.emplace_back(RankGauge::FIRST);
	rankvector.emplace_back(RankGauge::SECOND);
	rankvector.emplace_back(RankGauge::MAX);
}

Gauge::~Gauge()
{
}

void Gauge::initialize()
{

	m_gauge = ONEGAUGE;
	m_RankGauge = RankGauge::FIRST;
}

void Gauge::update()
{
	rankCheck();
}

void Gauge::draw(const Renderer& _renderer)
{
	_renderer.getDraw2D().string(std::to_string(m_RankGauge), &GSvector2(0, 50), 50);
	_renderer.getDraw2D().textrue(TEXTURE_ID::BLACK, &GSvector2(0,0), &GSrect(0,0,MAXGAUGE,30),&GSvector2(0,0),&GSvector2(1,1),0.0f);
	_renderer.getDraw2D().textrue(TEXTURE_ID::CLEAR, &GSvector2(0, 0), &GSrect(0, 0, m_gauge, 30), &GSvector2(0, 0), &GSvector2(1, 1),0.0f,&GScolor(0.0f,1.0f,0.0f,1.0f));
}

void Gauge::up(float _scale)
{
	add(_scale);
}
////////////////////////////////////////////////////
bool Gauge::down(float _scale)
{
	if (_scale > m_gauge)
	{
		return false;
	}
	add(-_scale);
	return true;
}
//////////////////////////////////////////////////////
void Gauge::downGauge(int _rank)
{
	if (ONEGAUGE * _rank > m_gauge)
	{
		return;
	}
	add(-ONEGAUGE * _rank);
}

float Gauge::scale(float def)
{
	return log(def+(m_gauge*0.1f));
}

void Gauge::rankCheck()
{
	int num;
	num = m_gauge / ONEGAUGE;
	m_RankGauge = rankvector[num];
}

void Gauge::add(float _point)
{
	Math::Clamp clamp;
	m_gauge = clamp(m_gauge + _point, MINGAUGE, MAXGAUGE);
}
