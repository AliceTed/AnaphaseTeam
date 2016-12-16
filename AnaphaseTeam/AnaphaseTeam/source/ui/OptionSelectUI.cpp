#include "..\..\header\ui\OptionSelectUI.h"
#include <algorithm>
const GSvector2 OptionSelectUI::DEFAULTSCALE = GSvector2(1.0f, 1.0f);
const GSvector2 OptionSelectUI::SELECTSCALE = GSvector2(1.3f, 1.3f);
const float OptionSelectUI::LERPTIME = 0.00f;

OptionSelectUI::OptionSelectUI()
	:m_option(OPTION::CONFIG)

{
}

OptionSelectUI::~OptionSelectUI()
{
}

void OptionSelectUI::initialize()
{
	m_images.clear();
	m_option = OPTION::CONFIG;
	
}

void OptionSelectUI::add(OPTION _name, const ScaleImage & _image)
{
	m_images.insert(std::make_pair(_name, _image));
}

void OptionSelectUI::update(float _deltaTime)
{
	std::for_each(m_images.begin(), m_images.end(), [_deltaTime](SelectOption& value) {value.second.update(_deltaTime); });
}

void OptionSelectUI::draw(IRenderer * _renderer)
{
	std::for_each(m_images.begin(), m_images.end(), [&_renderer](SelectOption& value) {value.second.draw(_renderer); });
	
}

void OptionSelectUI::previous()
{
	auto itr = m_images.find(m_option);
	if (itr == m_images.begin())
	{
		itr = m_images.end();
	}
	itr--;
	change(itr->first);
}

void OptionSelectUI::next()
{
	auto itr = m_images.find(m_option);
	itr++;
	if (itr == m_images.end())
	{
		change(m_images.begin()->first);
		return;
	}
	change(itr->first);
}

const OPTION OptionSelectUI::current() const
{
	return m_option;
}

void OptionSelectUI::change(OPTION _next)
{
	m_images.at(m_option).start(SELECTSCALE, DEFAULTSCALE, LERPTIME);
	m_option = _next;
	m_images.at(m_option).start(DEFAULTSCALE, SELECTSCALE, LERPTIME);
}

void OptionSelectUI::startChange()
{
	change(m_option);
}
