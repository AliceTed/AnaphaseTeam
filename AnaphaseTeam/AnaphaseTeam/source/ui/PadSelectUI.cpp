#include "..\..\header\ui\PadSelectUI.h"
#include <algorithm>

const GSvector2 PadSelectUI::DEFAULTSCALE = GSvector2(1.0f, 1.0f);
const GSvector2 PadSelectUI::SELECTSCALE = GSvector2(1.3f, 1.3f);
const float PadSelectUI::LERPTIME = 0.00f;

PadSelectUI::PadSelectUI()
	:m_pad(PAD::PAD_A)
{
}

PadSelectUI::~PadSelectUI()
{
}

void PadSelectUI::initialize()
{
	m_images.clear();
	m_pad = PAD::PAD_A;
}

void PadSelectUI::add(PAD _name, const ScaleImage & _image)
{
	m_images.insert(std::make_pair(_name, _image));

}

void PadSelectUI::update(float _deltaTime)
{
	std::for_each(m_images.begin(), m_images.end(), [_deltaTime](SelectPad& value) {value.second.update(_deltaTime); });
}

void PadSelectUI::draw(IRenderer * _renderer)
{
	std::for_each(m_images.begin(), m_images.end(), [&_renderer](SelectPad& value) {value.second.draw(_renderer); });
}

void PadSelectUI::previous()
{
	auto itr = m_images.find(m_pad);
	if (itr == m_images.begin())
	{
		itr = m_images.end();
	}
	itr--;
	change(itr->first);
}


void PadSelectUI::next()
{
	auto itr = m_images.find(m_pad);
	itr++;
	if (itr == m_images.end())
	{
		change(m_images.begin()->first);
		return;
	}
	change(itr->first);
}


const PAD PadSelectUI::current() const
{
	return m_pad;
}

void PadSelectUI::change(PAD _next)
{
	m_images.at(m_pad).start(SELECTSCALE, DEFAULTSCALE, LERPTIME);
	m_pad = _next;
	m_images.at(m_pad).start(DEFAULTSCALE, SELECTSCALE, LERPTIME);
}

void PadSelectUI::startChange()
{
	change(m_pad);
}
