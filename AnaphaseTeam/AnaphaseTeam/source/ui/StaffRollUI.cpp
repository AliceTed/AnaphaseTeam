#include "../../header/ui/StaffRollUI.h"
#include "../../header/data/stream/DataReader.h"
#include "../../header/data/Message.h"

#include <vector>
#include <sstream>
#include <algorithm>

static const GSvector2 m_strat = GSvector2(500, 730);
static const GSvector2 m_end = GSvector2(500, -10);

StaffRollUI::StaffRollUI()
	:m_texts(),
	m_words(),
	m_timer(1)
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
	m_timer.update(_deltaTime);
	for (auto& i : m_texts)
	{
		i.update(_deltaTime);
	}
	createText();
	remove();
}

void StaffRollUI::draw(IRenderer * _renderer)
{
	for (auto& i : m_texts)
	{
		i.draw(_renderer);
	}
}

bool StaffRollUI::isEnd() const
{
	return m_words.empty() && m_texts.empty();
}

void StaffRollUI::read()
{
	m_words.emplace_back("STAFFROLL");
	m_words.emplace_back("ꎓ��@��");
	m_words.emplace_back("�����@�T��");
	m_words.emplace_back("�v�H�@��");
	m_words.emplace_back("�L�y�@�E��");
	m_words.emplace_back("�N�ˁ@��");
	m_words.emplace_back("�a�J�@�m��");
	m_words.emplace_back("�g���@���");
	m_words.emplace_back("���؁@����");
	m_words.emplace_back("�Í��@��");
	m_words.emplace_back("��c�@�k��");
	m_words.emplace_back("��`�@�T�k");

	m_words.emplace_back("�f�ޒ�");

	m_words.emplace_back("http://www.flickr.com/photos/karen_roe/7881746364/ by Karen Roe (modified by ���₦��������)");
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
