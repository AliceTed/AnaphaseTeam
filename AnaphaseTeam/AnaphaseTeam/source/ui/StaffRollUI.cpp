#include "../../header/ui/StaffRollUI.h"
#include "../../header/data/stream/DataReader.h"
#include "../../header/data/Message.h"

#include <vector>
#include <sstream>

static const GSvector2 m_strat = GSvector2(0,80);
static const GSvector2 m_end = GSvector2(200, 0);

StaffRollUI::StaffRollUI()
{
}

StaffRollUI::~StaffRollUI()
{
}

void StaffRollUI::initilize()
{
	read();
}

void StaffRollUI::update(float _deltaTime)
{
	/*for (auto i : m_texts)
	{
		i.update(_deltaTime);
	}*/
}

void StaffRollUI::draw(IRenderer * _renderer)
{
	for (auto i : m_texts)
	{
		i.draw(_renderer);
	}
}

void StaffRollUI::read()
{
	m_words.emplace_back("ê“¡@•à");
	m_words.emplace_back("¼”ö@—T–ç");
	m_words.emplace_back("‹vH@‰ë");
	m_words.emplace_back("—L•y@—E”¿");
	m_words.emplace_back("ŒN’Ë@ãÄ");
	m_words.emplace_back("a’J@’m÷");
	m_words.emplace_back("‹gŒ³@‰ëŠì");
	m_words.emplace_back("‚–Ø@Œ’‘¾");
	m_words.emplace_back("ŒÃ‚@ãÄ");
	m_words.emplace_back("‘å“c@k‰î");
	m_words.emplace_back("‘åŠ`@—Tk");

	m_words.emplace_back("‘fŞ’ñ‹Ÿ");

	m_words.emplace_back("http://www.flickr.com/photos/karen_roe/7881746364/ by Karen Roe (modified by ‚ ‚â‚¦‚àŒ¤‹†Š)");
	m_words.emplace_back("is licensed under a Creative Commons license:");
	m_words.emplace_back("http://creativecommons.org/licenses/by/2.0/deed.en");

	//m_texts.emplace_back(MoveText(m_words[0], m_strat, m_end, 10));
	//m_texts.emplace_back(MoveText(m_words[1], m_strat, m_end, 64));
	//m_texts.emplace_back(MoveText(m_words[2], m_strat, m_end, 64));

	for (int i = 0; i < m_words.size(); i++)
	{
		m_texts.emplace_back(MoveText(m_words[i], GSvector2(30,10+(i*25)), m_end, 20));
	}
}
