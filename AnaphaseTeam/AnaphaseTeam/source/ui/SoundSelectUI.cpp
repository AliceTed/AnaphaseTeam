#include "..\..\header\ui\SoundSelectUI.h"
#include <algorithm>

const GSvector2 SoundSelectUI::DEFAULTSCALE = GSvector2(1.0f, 1.0f);
const GSvector2 SoundSelectUI::SELECTSCALE = GSvector2(1.3f, 1.3f);
const float SoundSelectUI::LERPTIME = 0.00f;

SoundSelectUI::SoundSelectUI()
	:m_sound(SOUND::BGM)
{
}

SoundSelectUI::~SoundSelectUI()
{
}

void SoundSelectUI::initialize()
{
	m_images.clear();
	m_sound = SOUND::BGM;
}

void SoundSelectUI::add(SOUND _name, const ScaleImage & _image)
{
	m_images.insert(std::make_pair(_name, _image));
}

void SoundSelectUI::next()
{
	auto itr = m_images.find(m_sound);
	itr++;
	if (itr == m_images.end())
	{
		change(m_images.begin()->first);
		return;
	}
	change(itr->first);
}

void SoundSelectUI::update(float _deltaTime)
{
	std::for_each(m_images.begin(), m_images.end(), [_deltaTime](SelectSound& value) {value.second.update(_deltaTime); });
}

void SoundSelectUI::draw(IRenderer * _renderer)
{
	std::for_each(m_images.begin(), m_images.end(), [&_renderer](SelectSound& value) {value.second.draw(_renderer); });
}

void SoundSelectUI::previous()
{
	auto itr = m_images.find(m_sound);
	if (itr == m_images.begin())
	{
		itr = m_images.end();
	}
	itr--;
	change(itr->first);
}

const SOUND SoundSelectUI::current() const
{
	return m_sound;
}

void SoundSelectUI::startChange()
{
	change(m_sound);
}

void SoundSelectUI::change(SOUND _next)
{
	m_images.at(m_sound).start(SELECTSCALE, DEFAULTSCALE, LERPTIME);
	m_sound = _next;
	m_images.at(m_sound).start(DEFAULTSCALE, SELECTSCALE, LERPTIME);
}
