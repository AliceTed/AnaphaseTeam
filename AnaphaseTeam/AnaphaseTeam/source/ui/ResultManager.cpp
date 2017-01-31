#include "../header/ui/ResultManager.h"
#include "renderer/IRenderer.h"
#include "renderer/define/NumberSpriteRenderDesc.h"
#include "renderer/define/SpriteRenderDesc.h"
#include "data/id/TEXTURE_ID.h"
#include "ui/Soul.h"
#include "math/Random.h"
#include "../header/data/stream/DataReader.h"
#include "data/Message.h"

#include <sstream>
#include <vector>

ResultManager::ResultManager()
	: m_score(0),
	m_soul(),
	m_rank(),
	m_scoreValue(0),
	m_createInterval(0),
	m_resultUi(GSvector2(200, 200), GSvector2(600, 200), 1)
{
}

ResultManager::~ResultManager()
{
}

void ResultManager::initilize()
{
	read();
	m_soulPos.clear();
	create();
	m_soul.initialize();
	m_rank.initilize();
	m_rank.calc_Rank(m_scoreValue);
	m_score.initialize();
	m_createInterval.initialize();
	//m_resultUi.Initilize();
}

void ResultManager::update(float _deltaTime)
{
	//if (!m_resultUi.isDead())
	//{
	//	m_resultUi.update(_deltaTime);
	//	return;
	//}
	if (!m_score.isEnd())
	{
		m_score.update(1);
		return;
	}
	if (m_soul.isEmpty())
	{
		m_rank.update(_deltaTime);
	}
	m_soul.update(_deltaTime);
	m_soul.remove();
	if (!m_createInterval.isEnd())
	{
		m_createInterval.update(1);
		Math::Random rand;
		SoulPtr soul = std::make_shared<Soul>(m_soulPos[rand(0, 24)], GSvector2(400, 400), 2);
		m_soul.add(soul);
		return;
	}


}

void ResultManager::draw(IRenderer * _renderer)
{
	//m_resultUi.draw(_renderer);
	//if (m_resultUi.isDead())
	//{
		m_score.accept([&](float _time, float _endtime)
		{
			NumberSpriteRenderDesc desc;
			desc.decimal = 0;
			desc.digit = 1;
			desc.size = GSvector2(80, 124);
			desc.number = _time;
			desc.matrix.translate(GSvector3(715, 360, 0));
			desc.textureID = static_cast<GSuint>(TEXTURE_ID::NUMBER);
			_renderer->render(desc);
		});
	//}

	m_soul.draw(_renderer);

	if (m_soul.isEmpty())
	{
		m_rank.draw(_renderer);
	}

}

bool ResultManager::isNex()
{
	return m_rank.isDead();
}

void ResultManager::read()
{
	DataReader reader;
	std::vector<std::string> data;

	if (!reader(&data, "./res/data/score", ".msk"))
	{
		Message error;
		error("Score", "./res/data/score���Ȃ�");
		return;
	}
	if (data.size() == 0)
	{
		Message error;
		error("Score", "score���ǂݍ��߂܂���");
		return;
	}

	std::stringstream ss(data[0]);

	ss >> m_scoreValue;
	//m_scoreValue = 150;

	float end = m_scoreValue / 60.0f;
	m_score.setEndTime(end);
	m_createInterval.setEndTime(end);
}

void ResultManager::create()
{
	for (int x = 0; x <= 4; x++)
	{
		for (int y = 0; y <= 4; y++)
		{
			m_soulPos.emplace_back(160 * x, 180 * y);
		}
	}
}