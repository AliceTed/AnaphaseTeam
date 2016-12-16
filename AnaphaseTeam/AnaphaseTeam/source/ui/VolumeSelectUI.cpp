#include "..\..\header\ui\VolumeSelectUI.h"
#include <algorithm>

const GSvector2 VolumeSelectUI::DEFAULTSCALE = GSvector2(1.0f, 1.0f);
const GSvector2 VolumeSelectUI::SELECTSCALE = GSvector2(1.3f, 1.3f);
const float VolumeSelectUI::LERPTIME = 0.00f;

VolumeSelectUI::VolumeSelectUI()
	:m_volume(VOLUME::NORMAL)
{
}

VolumeSelectUI::~VolumeSelectUI()
{
}

void VolumeSelectUI::initialize()
{
	m_images.clear();
	m_volume = VOLUME::NORMAL;
}

void VolumeSelectUI::add(VOLUME _name, const ScaleImage & _image)
{
	m_images.insert(std::make_pair(_name, _image));
}

void VolumeSelectUI::next()
{
	auto itr = m_images.find(m_volume);
	itr++;
	if (itr == m_images.end())
	{
		change(m_images.begin()->first);
		return;
	}
	change(itr->first);
}

void VolumeSelectUI::update(float _deltaTime)
{
	std::for_each(m_images.begin(), m_images.end(), [_deltaTime](SelectVolime& value) {value.second.update(_deltaTime); });
}

void VolumeSelectUI::draw(IRenderer * _renderer)
{
	std::for_each(m_images.begin(), m_images.end(), [&_renderer](SelectVolime& value) {value.second.draw(_renderer); });
}

void VolumeSelectUI::previous()
{
	auto itr = m_images.find(m_volume);
	if (itr == m_images.begin())
	{
		itr = m_images.end();
	}
	itr--;
	change(itr->first);
}

const VOLUME VolumeSelectUI::current() const
{
	return m_volume;
}

void VolumeSelectUI::startChange()
{
	change(m_volume);
}

void VolumeSelectUI::change(VOLUME _next)
{
	m_images.at(m_volume).start(SELECTSCALE, DEFAULTSCALE, LERPTIME);
	m_volume = _next;
	m_images.at(m_volume).start(DEFAULTSCALE, SELECTSCALE, LERPTIME);
}
