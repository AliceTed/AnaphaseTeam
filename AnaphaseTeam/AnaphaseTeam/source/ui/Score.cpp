#include "..\..\header\ui\Score.h"

Score::Score()
	:m_position(300,300),
	m_number(TEXTURE_ID::NUMBER, m_position),
	m_score(0), m_timer(0), m_hit(false)
{
}

Score::~Score()
{
}

void Score::initialize()
{
	m_number.initilize();
	m_position = GSvector2(300, 300);
	reset();
	m_hit = false;
}

void Score::add(int _score)
{
	m_number.reset();
	timerSet();
	m_hit = true;
	m_score += _score;
	if (m_score < 50)
	{
		feverTime(20, _score, 2);
	}
	feverTime(50, _score, 3);
}

void Score::update(float _deltaTime)
{
	m_number.update(_deltaTime);
	hit();
	if (m_timer <= 0)
	{
		reset();
	}
}

void Score::hit()
{
	if (m_hit)
	{
		m_number.flashing(0.3, 2.7);
		timerStart();
		m_number.scroll();
	}
}

void Score::timerSet()
{
	m_timer = 60 * 3;
}

void Score::timerStart()
{
	m_timer--;
}

void Score::feverTime(int _limit, int _score, int _double)
{
	if (m_score > _limit)
	{
		m_score += _score * _double;
	}
}

void Score::reset()
{
	m_timer = 60 * 3;
	m_score = 0;
	m_hit = false;
}

void Score::draw(IRenderer * _renderer)
{
	m_number.draw(_renderer, m_score);
}
