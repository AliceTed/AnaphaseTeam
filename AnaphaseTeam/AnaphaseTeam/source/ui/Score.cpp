#include "..\..\header\ui\Score.h"
#include "../header/data/stream/DataWriter.h"
#include "data\Message.h"

Score::Score()
	:m_number(TEXTURE_ID::NUMBER),
	m_score(0), m_timer(0), m_hit(false), m_total(0)
{
}

Score::~Score()
{
}

void Score::initialize()
{
	m_total = 0;
	m_number.initilize();
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

void Score::update(float deltaTime)
{
	m_number.update(deltaTime);
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
	timerSet();
	record(m_score);
	m_score = 0;
	m_hit = false;
}

void Score::draw(IRenderer * _renderer)
{
 	m_number.draw(_renderer, m_score);
}

//Score‚Ì‹L˜^
void Score::record(int _score)
{
	m_current.emplace_back(_score);
}

void Score::scoreSave()
{
	calc_Total();
	DataWriter writer;
	std::vector<std::string> save;
	save.emplace_back(std::to_string(m_total));

	if (writer(save, "./res/data/score", ".msk"))return;
	Message error;
	error("Score", "./res/data/score‚ª‚È‚¢");

}

void Score::calc_Total()
{
	m_total = 0;
	for (auto i:m_current)
	{
		m_total += i;
	}
}

