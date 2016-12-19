#include "..\..\header\ui\Score.h"

Score::Score()
	:m_number(TEXTURE_ID::NUMBER, GSvector2(100, 100)),
	m_score(0), m_timer(0)
{
}

Score::~Score()
{
}

void Score::initialize()
{
	reset();
}

void Score::add(int _score)
{
	m_score = m_score + _score;
	Continuation();
}

void Score::update(float _deltaTime)
{
	countStart();
	if (m_timer < 0)
	{
		reset();
	}
}

void Score::countStart()
{
	m_timer --;
}

void Score::Continuation()
{
	m_timer = 60 * 3;
}

void Score::reset()
{
	m_timer = 60 * 3;
	m_score = 0;
}

void Score::draw(IRenderer * _renderer)
{
	m_number.draw(_renderer, m_score);
}
