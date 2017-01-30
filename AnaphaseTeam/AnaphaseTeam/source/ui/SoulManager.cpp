#include "..\..\header\ui\SoulManager.h"
#include "renderer/IRenderer.h"
#include "../../header/ui/Soul.h"
#include <algorithm>

SoulManager::SoulManager()
	:m_particles()
{
}

SoulManager::~SoulManager()
{
	m_particles.clear();
}

void SoulManager::initialize()
{
	m_particles.clear();
}

void SoulManager::update(float _deltaTime)
{
	std::for_each(m_particles.begin(), m_particles.end(), [_deltaTime](SoulPtr& p) {p->update(_deltaTime); });
}

void SoulManager::draw(IRenderer * _renderer)
{
	std::for_each(m_particles.begin(), m_particles.end(), [_renderer](SoulPtr& p) {p->draw(_renderer); });
}

void SoulManager::remove()
{
	auto itr = std::remove_if(m_particles.begin(),m_particles.end(), [](SoulPtr& _p){return _p->isDead();});
	m_particles.erase(itr, m_particles.end());
}

void SoulManager::add(SoulPtr & _soul)
{
	m_particles.emplace_back(_soul);
}

bool SoulManager::isEmpty() const
{
	return m_particles.empty();
}

