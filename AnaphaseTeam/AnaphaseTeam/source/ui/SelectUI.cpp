#include "../../header/ui/SelectUI.h"
#include <algorithm>
const GSvector2 SelectUI::DEFAULTSCALE = GSvector2(1.0f, 1.0f);
const GSvector2 SelectUI::SELECTSCALE = GSvector2(1.3f, 1.3f);
const GSvector2 SelectUI::DECISIONSCALE = GSvector2(2.5f, 2.5f);
const float SelectUI::LERPTIME = 0.05f;
SelectUI::SelectUI()
	:m_current(Select::GAMESTART),
	m_images(),
	m_timer(0.0f)
{
}

SelectUI::~SelectUI()
{
}

void SelectUI::initialize()
{
	m_images.clear();
	m_timer = 0;
}

void SelectUI::add(Select _name, const ScaleImage & _image)
{
	m_images.insert(std::make_pair(_name, _image));
}

void SelectUI::update(float deltaTime)
{
	//std::for_each(m_images.begin(), m_images.end(), [deltaTime](SelectValue& value) {value.second.update(deltaTime); });
	const unsigned int size = 3;
	Select select[size] =
	{
		Select::GAMESTART,
		Select::OPTION,
		Select::EXIT
	};
	m_timer++;
	for (unsigned int i = 0; i < size; i++)
	{
		if (m_timer > i * 60.0f)
		{
			m_images.at(select[i]).update(deltaTime);
		}

	}
	if (m_timer > 3 * 60.0f)
	{
		m_timer = 3 * 60.0f;
	}

}

void SelectUI::draw(IRenderer * _renderer)
{
	std::for_each(m_images.begin(), m_images.end(), [&_renderer](SelectValue& value) {value.second.draw(_renderer); });
}
void SelectUI::next()
{
	auto itr = m_images.find(m_current);
	itr++;
	if (itr == m_images.end())
	{
		change(m_images.begin()->first);
		return;
	}
	change(itr->first);
}
void SelectUI::previous()
{
	auto itr = m_images.find(m_current);
	if (itr == m_images.begin())
	{
		itr = m_images.end();
	}
	itr--;
	change(itr->first);
}
void SelectUI::change(Select _next)
{
	m_images.at(m_current).start(SELECTSCALE, DEFAULTSCALE, LERPTIME);
	m_current = _next;
	m_images.at(m_current).start(DEFAULTSCALE, SELECTSCALE, LERPTIME);
}

const Select SelectUI::currentSelect() const
{
	return m_current;
}

void SelectUI::startChange()
{
	change(m_current);
}

void SelectUI::startMove()
{
	m_images.at(m_current).moveStart(GSvector2(365, 200), LERPTIME * 10.0f);
	m_images.at(m_current).start(SELECTSCALE, DECISIONSCALE, LERPTIME *10.0f);
	for (auto& i : m_images)
	{
		if (i.first != m_current)
		{
			m_images.at(i.first).moveStart(GSvector2(365, 800), LERPTIME* 10.0f);
		}
	}
}

bool SelectUI::isStart()
{
	return m_images.at(Select::EXIT).isStart();
}


