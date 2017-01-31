#include "../../header/ui/StaffRollUI.h"
#include "../../header/data/stream/DataReader.h"
#include "../../header/data/Message.h"
#include "../../header/device/GameDevice.h"

#include <vector>
#include <sstream>
#include <algorithm>

static const GSvector2 m_strat = GSvector2(100, 720);
static const GSvector2 m_end = GSvector2(100, -50);

StaffRollUI::StaffRollUI()
	:m_texts(),
	m_words(),
	m_timer(1),
	m_count(0)
{
}

StaffRollUI::~StaffRollUI()
{
}

void StaffRollUI::initilize()
{
	m_count = 0;
	read();
}

void StaffRollUI::update(float _deltaTime)
{
	m_timer.update(_deltaTime);
	for (auto& i : m_texts)
	{
		i.update(_deltaTime);
	}
	createText();
	remove();
	push();
}

void StaffRollUI::draw(IRenderer * _renderer)
{
	for (auto& i : m_texts)
	{
		i.draw(_renderer);
	}
}

void StaffRollUI::push()
{
	if (GameDevice::getInstacnce().input()->jump())
	{
		m_count++;
	}

	if (m_count >= 2)
	{
		m_words.clear();
		m_texts.clear();
	}
}

bool StaffRollUI::isEnd() const
{
	return m_words.empty() && m_texts.empty();
}

void StaffRollUI::read()
{
	m_words.emplace_back("STAFFROLL");
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

	m_words.emplace_back("http://www.flickr.com/photos/karen_roe/7881746364/");
	m_words.emplace_back("by Karen Roe (modified by ‚ ‚â‚¦‚àŒ¤‹†Š)");
	m_words.emplace_back("is licensed under a Creative Commons license:");
	m_words.emplace_back("http://creativecommons.org/licenses/by/2.0/deed.en");
}

void StaffRollUI::createText()
{
	if (!m_timer.isEnd())return;
	if (m_words.empty())return;
	m_timer.initialize();
	auto first = m_words.begin();
	m_texts.emplace_back(MoveText(*first, m_strat, m_end, 35));
	m_words.erase(first);

}

void StaffRollUI::remove()
{
	auto itr = std::remove_if(m_texts.begin(), m_texts.end(), [](MoveText& _text) {return _text.isEnd(); });
	m_texts.erase(itr, m_texts.end());
}
