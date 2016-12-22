#include "..\..\header\ui\Score.h"

Score::Score()
	:m_number(TEXTURE_ID::NUMBER, GSvector2(300, 300)),
	m_score(0), m_timer(0), m_hit(false)
{
}

Score::~Score()
{
}

void Score::initialize()
{
	m_number.initilize();
	reset();
	m_hit = false;
}

void Score::add(int _score)
{
	m_number.start();
	timerSet();
	m_hit = true;
	m_score += _score;
	//feverTime(20, _score, 2);
	//feverTime(50, _score, 3);
	
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
		timerStart();
		m_number.decrease(3);
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

void Score::feverTime(int _limit , int _score ,int _double)
{
	if (m_score >= _limit)
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
	//m_number.drawNum(_renderer, m_score, 100, 100);
}
